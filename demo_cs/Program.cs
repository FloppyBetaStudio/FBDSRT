using Newtonsoft.Json;

namespace demo_cs
{
    internal static class Program
    {
        /// <summary>
        ///  The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            // To customize application configuration such as set high DPI settings or default font,
            // see https://aka.ms/applicationconfiguration.
            ApplicationConfiguration.Initialize();
            Form1 form = new();
            HttpClient client = new();
            MessageBox.Show(client.GetStringAsync($"http://127.0.0.1:1984/pluginReg?name=sayHallo&key=iruanp.com&hwnd={form.textBox1.Handle}").Result); // ע��Ӧ��
            MessageBox.Show(client.GetStringAsync("http://127.0.0.1:1984/eventReg_onPlayerJoin?name=sayHallo&key=iruanp.com").Result);  // ע�������
            form.textBox1.TextChanged += (sender, e) => // �������ݣ�JSON��
            {
                Dictionary<string, Dictionary<string, object>> data = JsonConvert.DeserializeObject<Dictionary<string, Dictionary<string, object>>>(form.textBox1.Text);    // ��������
                Dictionary<string, object> @event = data["event"];
                Dictionary<string, object> player = data["player"];
                if ($"{@event["type"]}" == "onPlayerJoin")
                {
                    client.GetAsync($"http://127.0.0.1:1984/runcmd?key=iruanp.com&cmd=tell \"{player["name"]}\" Hallo! Your permission level: {player["permission"]}");
                }
            };
            Application.Run(form);
        }
    }
}