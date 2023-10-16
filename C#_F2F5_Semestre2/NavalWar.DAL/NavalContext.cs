using Microsoft.EntityFrameworkCore;
using NavalWar.DAL.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NavalWar.DAL
{
    public class NavalContext : DbContext
    {
        public NavalContext(DbContextOptions<NavalContext> options):base(options) {
        }

        public DbSet<Player> Players { get; set; }
        public DbSet<Session> Sessions { get; set; }
        public DbSet<Board> Boards { get; set; }
        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Player>()
                .ToTable("Players")
                .HasOne(b => b.Session)
                .WithMany()
                .HasForeignKey(p => p.PlayerSessionId);

            modelBuilder.Entity<Player>()
                .HasOne(p => p.personnal)
                .WithMany()
                .HasForeignKey(p => p._personalBoard)
                .OnDelete(DeleteBehavior.NoAction);

            modelBuilder.Entity<Player>()
                .HasOne(p => p.shot)
                .WithMany()
                .HasForeignKey(p => p._shotBoard)
                .OnDelete(DeleteBehavior.NoAction);

            modelBuilder.Entity<Session>()
                .ToTable("Session");

            modelBuilder.Entity<Board>()
                .ToTable("Boards")
                .HasKey(s => s.Id);

        }
    }
}
