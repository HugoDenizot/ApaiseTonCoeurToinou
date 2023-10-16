using Microsoft.EntityFrameworkCore;
using NavalWar.Business;
using NavalWar.DAL;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.

builder.Services.AddControllers();
builder.Services.AddAutoMapper(typeof(Program));
builder.Services.AddCors(options =>
{
    options.AddDefaultPolicy(builder =>
    {
        builder.WithOrigins("http://localhost:4200")
               .AllowAnyHeader()
               .AllowAnyMethod();
    });
});

// Learn more about configuring Swagger/OpenAPI at https://aka.ms/aspnetcore/swashbuckle
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();
//builder.Services.AddDbContext<NavalContext>(options => options.UseSqlServer("Server=tcp:navalwargroupe3.database.windows.net,1433;Initial Catalog=DatabaseNavalWar;Persist Security Info=False;User ID=hudenizot;Password=navalwar3.;MultipleActiveResultSets=False;Encrypt=True;TrustServerCertificate=False;Connection Timeout=30;"));
builder.Services.AddDbContext<NavalContext>(options =>
options.UseSqlServer("Server=tcp:navalwargroupe3.database.windows.net,1433;Initial Catalog=DatabaseNavalWar;User ID=hudenizot;Password=navalwar3.;Encrypt=True;", builder => builder.EnableRetryOnFailure()));
/*builder.Services.AddDbContext<NavalContext>(options => options.UseSqlServer("Server=(localdb)\\mssqllocaldb;Database=<yourDatabase >; Trusted_Connection = True; MultipleActiveResultSets = true "));
*/

builder.Services.AddScoped<IGameService, GameService>();
builder.Services.AddScoped<ISessionRepository, SessionRepository>();
var app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

app.UseHttpsRedirection();

app.UseAuthorization();

app.MapControllers();

app.UseCors();

app.Run();

