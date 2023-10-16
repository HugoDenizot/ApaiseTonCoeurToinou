﻿// <auto-generated />
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Infrastructure;
using Microsoft.EntityFrameworkCore.Metadata;
using Microsoft.EntityFrameworkCore.Migrations;
using Microsoft.EntityFrameworkCore.Storage.ValueConversion;
using NavalWar.DAL;

#nullable disable

namespace NavalWar.DAL.Migrations
{
    [DbContext(typeof(NavalContext))]
    [Migration("20230310013345_init")]
    partial class init
    {
        /// <inheritdoc />
        protected override void BuildTargetModel(ModelBuilder modelBuilder)
        {
#pragma warning disable 612, 618
            modelBuilder
                .HasAnnotation("ProductVersion", "7.0.2")
                .HasAnnotation("Relational:MaxIdentifierLength", 128);

            SqlServerModelBuilderExtensions.UseIdentityColumns(modelBuilder);

            modelBuilder.Entity("NavalWar.DAL.Models.Board", b =>
                {
                    b.Property<int>("Id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int");

                    SqlServerPropertyBuilderExtensions.UseIdentityColumn(b.Property<int>("Id"));

                    b.Property<string>("cellules")
                        .IsRequired()
                        .HasColumnType("nvarchar(max)");

                    b.HasKey("Id");

                    b.ToTable("Boards", (string)null);
                });

            modelBuilder.Entity("NavalWar.DAL.Models.Player", b =>
                {
                    b.Property<int>("_id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int");

                    SqlServerPropertyBuilderExtensions.UseIdentityColumn(b.Property<int>("_id"));

                    b.Property<int>("PlayerSessionId")
                        .HasColumnType("int");

                    b.Property<string>("_name")
                        .IsRequired()
                        .HasColumnType("nvarchar(max)");

                    b.Property<int>("_personalBoard")
                        .HasColumnType("int");

                    b.Property<int>("_shotBoard")
                        .HasColumnType("int");

                    b.HasKey("_id");

                    b.HasIndex("PlayerSessionId");

                    b.HasIndex("_personalBoard");

                    b.HasIndex("_shotBoard");

                    b.ToTable("Players", (string)null);
                });

            modelBuilder.Entity("NavalWar.DAL.Models.Session", b =>
                {
                    b.Property<int>("ID")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int");

                    SqlServerPropertyBuilderExtensions.UseIdentityColumn(b.Property<int>("ID"));

                    b.Property<string>("NameJoueurEnCours")
                        .IsRequired()
                        .HasColumnType("nvarchar(max)");

                    b.HasKey("ID");

                    b.ToTable("Session", (string)null);
                });

            modelBuilder.Entity("NavalWar.DAL.Models.Player", b =>
                {
                    b.HasOne("NavalWar.DAL.Models.Session", "Session")
                        .WithMany()
                        .HasForeignKey("PlayerSessionId")
                        .OnDelete(DeleteBehavior.Cascade)
                        .IsRequired();

                    b.HasOne("NavalWar.DAL.Models.Board", "personnal")
                        .WithMany()
                        .HasForeignKey("_personalBoard")
                        .OnDelete(DeleteBehavior.NoAction)
                        .IsRequired();

                    b.HasOne("NavalWar.DAL.Models.Board", "shot")
                        .WithMany()
                        .HasForeignKey("_shotBoard")
                        .OnDelete(DeleteBehavior.NoAction)
                        .IsRequired();

                    b.Navigation("Session");

                    b.Navigation("personnal");

                    b.Navigation("shot");
                });
#pragma warning restore 612, 618
        }
    }
}
