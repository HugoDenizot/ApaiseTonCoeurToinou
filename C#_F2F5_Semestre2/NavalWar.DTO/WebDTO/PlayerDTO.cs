using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NavalWar.DTO.WebDTO
{
    public class PlayerDTO
    {

        public int _id { get; set; }

        public string _name { get; set; }
        public static int _numNav = 5;
        public int SessionId { get; set; }
        public int _personalBoard { get; set; }
        public int _shotBoard { get; set; }


    }
}
