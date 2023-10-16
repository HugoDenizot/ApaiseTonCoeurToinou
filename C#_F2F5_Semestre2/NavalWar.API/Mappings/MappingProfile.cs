using AutoMapper;
using NavalWar.DAL.Models;
using NavalWar.DTO;
using NavalWar.DTO.WebDTO;

namespace NavalWar.API.Mappings
{
    public class MappingProfile : Profile
    {
       /* public MappingProfile()
        {
            CreateMap<BoardDto, Board>()
                .ForMember(dest => dest.Cells, opt => opt.MapFrom(src => src.Cells.Select(c => new Cell
                {
                    Row = c.Row,
                    Column = c.Column,
                    Status = (Cell.CellStatus)c.Status
                })));
            CreateMap<CellDto, Cell>();
            CreateMap<PlayerDTO, NavalWar.DAL.Models.Player>();
        }*/
    }
}
