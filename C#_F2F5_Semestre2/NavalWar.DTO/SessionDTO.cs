using NavalWar.DTO.WebDTO;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NavalWar.DTO
{
    public class SessionDTO
    {
        public SessionDTO() {
            NameJoueurEnCours = "Joueur1";
        }
        public int ID { get; set; }

        public string NameJoueurEnCours { get; set; }
    }
}
