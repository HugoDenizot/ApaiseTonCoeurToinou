using System.ComponentModel.DataAnnotations;
namespace NavalWar.DAL.Models
{
    public class Session
    {
        [Key]

        public int ID { get; set; }

        public string NameJoueurEnCours { get; set; }

    }
}
