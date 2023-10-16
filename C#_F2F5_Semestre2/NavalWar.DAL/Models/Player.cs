using System.ComponentModel.DataAnnotations;

namespace NavalWar.DAL.Models
{
    public class Player
    {
        [Key]
        public int _id { get; set; }

        public string _name { get; set; }

        public int _personalBoard { get; set; }

        public Board personnal { get; set; }

        public int _shotBoard { get; set; }

        public Board shot { get; set; }

        public int PlayerSessionId { get; set; }

        public Session Session { get; set; }
    }

}
