namespace NavalWar.API.NewFolder
{
    public class Startup
    {
        public void ConfigureServices(IServiceCollection services)
        {
            // configure CORS
            services.AddCors(options =>
            {
                options.AddDefaultPolicy(builder =>
                {
                    builder.WithOrigins("http://localhost:4200")
                           .AllowAnyHeader()
                           .AllowAnyMethod();
                });
            });

            // other service configurations
        }

        public void Configure(IApplicationBuilder app, IWebHostEnvironment env)
        {
            // enable CORS
            app.UseCors();

            // other app configurations
        }
    }
}
