// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "lev_quake.h"

lev_quake_t::lev_quake_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;
    m_sky_data = 0;
    m__io__raw_sky_data = 0;
    m_header = 0;
    m_sectors = 0;
    m_planes = 0;
    m_tiles = 0;
    m_vertices = 0;
    m_quads = 0;
    m_entities = 0;
    m_entity_polylinks = 0;
    m_entity_polylink_data1 = 0;
    m__io__raw_entity_polylink_data1 = 0;
    m_entity_polylink_data2 = 0;
    m__io__raw_entity_polylink_data2 = 0;
    m_entity_data = 0;
    m__io__raw_entity_data = 0;
    m_tile_texture_data = 0;
    m__io__raw_tile_texture_data = 0;
    m_tile_color_data = 0;
    m__io__raw_tile_color_data = 0;
    m_unknown = 0;
    m_resources = 0;
    m_unknown0 = 0;
    m_unknown1 = 0;
    m_unknown2 = 0;
    m_unknown3 = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::_read() {
    m__raw_sky_data = m__io->read_bytes(131104);
    m__io__raw_sky_data = new kaitai::kstream(m__raw_sky_data);
    m_sky_data = new sky_data_t(m__io__raw_sky_data, this, m__root);
    m_header = new header_t(m__io, this, m__root);
    m_sectors = new std::vector<sector_t*>();
    const int l_sectors = header()->num_sectors();
    for (int i = 0; i < l_sectors; i++) {
        m_sectors->push_back(new sector_t(m__io, this, m__root));
    }
    m_planes = new std::vector<plane_t*>();
    const int l_planes = header()->num_planes();
    for (int i = 0; i < l_planes; i++) {
        m_planes->push_back(new plane_t(m__io, this, m__root));
    }
    m_tiles = new std::vector<tile_t*>();
    const int l_tiles = header()->num_tiles();
    for (int i = 0; i < l_tiles; i++) {
        m_tiles->push_back(new tile_t(m__io, this, m__root));
    }
    m_vertices = new std::vector<vertex_t*>();
    const int l_vertices = header()->num_vertices();
    for (int i = 0; i < l_vertices; i++) {
        m_vertices->push_back(new vertex_t(m__io, this, m__root));
    }
    m_quads = new std::vector<quad_t*>();
    const int l_quads = header()->num_quads();
    for (int i = 0; i < l_quads; i++) {
        m_quads->push_back(new quad_t(m__io, this, m__root));
    }
    m_entities = new std::vector<entity_t*>();
    const int l_entities = header()->num_entities();
    for (int i = 0; i < l_entities; i++) {
        m_entities->push_back(new entity_t(i, m__io, this, m__root));
    }
    m_entity_polylinks = new std::vector<entity_polylink_t*>();
    const int l_entity_polylinks = header()->num_entity_polylinks();
    for (int i = 0; i < l_entity_polylinks; i++) {
        m_entity_polylinks->push_back(new entity_polylink_t(m__io, this, m__root));
    }
    m__raw_entity_polylink_data1 = m__io->read_bytes((header()->num_entity_polylink_data1_segments() * 2));
    m__io__raw_entity_polylink_data1 = new kaitai::kstream(m__raw_entity_polylink_data1);
    m_entity_polylink_data1 = new entity_polylink_data1_t(m__io__raw_entity_polylink_data1, this, m__root);
    m__raw_entity_polylink_data2 = m__io->read_bytes((header()->num_entity_polylink_data2_segments() * 4));
    m__io__raw_entity_polylink_data2 = new kaitai::kstream(m__raw_entity_polylink_data2);
    m_entity_polylink_data2 = new entity_polylink_data2_t(m__io__raw_entity_polylink_data2, this, m__root);
    m__raw_entity_data = m__io->read_bytes(header()->len_entity_data());
    m__io__raw_entity_data = new kaitai::kstream(m__raw_entity_data);
    m_entity_data = new entity_data_t(m__io__raw_entity_data, this, m__root);
    m__raw_tile_texture_data = m__io->read_bytes(header()->len_tile_texture_data());
    m__io__raw_tile_texture_data = new kaitai::kstream(m__raw_tile_texture_data);
    m_tile_texture_data = new tile_texture_data_t(m__io__raw_tile_texture_data, this, m__root);
    m__raw_tile_color_data = m__io->read_bytes(header()->len_tile_color_data());
    m__io__raw_tile_color_data = new kaitai::kstream(m__raw_tile_color_data);
    m_tile_color_data = new tile_color_data_t(m__io__raw_tile_color_data, this, m__root);
    m_unknown = new std::vector<std::string>();
    const int l_unknown = header()->num_unknown();
    for (int i = 0; i < l_unknown; i++) {
        m_unknown->push_back(m__io->read_bytes(128));
    }
    m_resources = new resources_t(m__io, this, m__root);
    m_unknown0 = new len_and_unknown_t(m__io, this, m__root);
    m_level_name = kaitai::kstream::bytes_to_str(m__io->read_bytes(32), std::string("ASCII"));
    m_unknown1 = new std::vector<uint32_t>();
    const int l_unknown1 = 9;
    for (int i = 0; i < l_unknown1; i++) {
        m_unknown1->push_back(m__io->read_u4be());
    }
    m_unknown2 = new len_and_unknown_t(m__io, this, m__root);
    m_unknown3 = new len_and_unknown_t(m__io, this, m__root);
}

lev_quake_t::~lev_quake_t() {
    _clean_up();
}

void lev_quake_t::_clean_up() {
    if (m__io__raw_sky_data) {
        delete m__io__raw_sky_data; m__io__raw_sky_data = 0;
    }
    if (m_sky_data) {
        delete m_sky_data; m_sky_data = 0;
    }
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (m_sectors) {
        for (std::vector<sector_t*>::iterator it = m_sectors->begin(); it != m_sectors->end(); ++it) {
            delete *it;
        }
        delete m_sectors; m_sectors = 0;
    }
    if (m_planes) {
        for (std::vector<plane_t*>::iterator it = m_planes->begin(); it != m_planes->end(); ++it) {
            delete *it;
        }
        delete m_planes; m_planes = 0;
    }
    if (m_tiles) {
        for (std::vector<tile_t*>::iterator it = m_tiles->begin(); it != m_tiles->end(); ++it) {
            delete *it;
        }
        delete m_tiles; m_tiles = 0;
    }
    if (m_vertices) {
        for (std::vector<vertex_t*>::iterator it = m_vertices->begin(); it != m_vertices->end(); ++it) {
            delete *it;
        }
        delete m_vertices; m_vertices = 0;
    }
    if (m_quads) {
        for (std::vector<quad_t*>::iterator it = m_quads->begin(); it != m_quads->end(); ++it) {
            delete *it;
        }
        delete m_quads; m_quads = 0;
    }
    if (m_entities) {
        for (std::vector<entity_t*>::iterator it = m_entities->begin(); it != m_entities->end(); ++it) {
            delete *it;
        }
        delete m_entities; m_entities = 0;
    }
    if (m_entity_polylinks) {
        for (std::vector<entity_polylink_t*>::iterator it = m_entity_polylinks->begin(); it != m_entity_polylinks->end(); ++it) {
            delete *it;
        }
        delete m_entity_polylinks; m_entity_polylinks = 0;
    }
    if (m__io__raw_entity_polylink_data1) {
        delete m__io__raw_entity_polylink_data1; m__io__raw_entity_polylink_data1 = 0;
    }
    if (m_entity_polylink_data1) {
        delete m_entity_polylink_data1; m_entity_polylink_data1 = 0;
    }
    if (m__io__raw_entity_polylink_data2) {
        delete m__io__raw_entity_polylink_data2; m__io__raw_entity_polylink_data2 = 0;
    }
    if (m_entity_polylink_data2) {
        delete m_entity_polylink_data2; m_entity_polylink_data2 = 0;
    }
    if (m__io__raw_entity_data) {
        delete m__io__raw_entity_data; m__io__raw_entity_data = 0;
    }
    if (m_entity_data) {
        delete m_entity_data; m_entity_data = 0;
    }
    if (m__io__raw_tile_texture_data) {
        delete m__io__raw_tile_texture_data; m__io__raw_tile_texture_data = 0;
    }
    if (m_tile_texture_data) {
        delete m_tile_texture_data; m_tile_texture_data = 0;
    }
    if (m__io__raw_tile_color_data) {
        delete m__io__raw_tile_color_data; m__io__raw_tile_color_data = 0;
    }
    if (m_tile_color_data) {
        delete m_tile_color_data; m_tile_color_data = 0;
    }
    if (m_unknown) {
        delete m_unknown; m_unknown = 0;
    }
    if (m_resources) {
        delete m_resources; m_resources = 0;
    }
    if (m_unknown0) {
        delete m_unknown0; m_unknown0 = 0;
    }
    if (m_unknown1) {
        delete m_unknown1; m_unknown1 = 0;
    }
    if (m_unknown2) {
        delete m_unknown2; m_unknown2 = 0;
    }
    if (m_unknown3) {
        delete m_unknown3; m_unknown3 = 0;
    }
}

lev_quake_t::tile_texture_data_t::tile_texture_data_t(kaitai::kstream* p__io, lev_quake_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::tile_texture_data_t::_read() {
    m_data = m__io->read_bytes(_parent()->header()->len_tile_texture_data());
}

lev_quake_t::tile_texture_data_t::~tile_texture_data_t() {
    _clean_up();
}

void lev_quake_t::tile_texture_data_t::_clean_up() {
}

lev_quake_t::entity_data_t::entity_data_t(kaitai::kstream* p__io, lev_quake_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::entity_data_t::_read() {
    m_data = m__io->read_bytes(_parent()->header()->len_entity_data());
}

lev_quake_t::entity_data_t::~entity_data_t() {
    _clean_up();
}

void lev_quake_t::entity_data_t::_clean_up() {
}

lev_quake_t::resource_0x6c_t::resource_0x6c_t(kaitai::kstream* p__io, lev_quake_t::resource_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::resource_0x6c_t::_read() {
    m_unknown0 = m__io->read_u2be();
    m_len_data = m__io->read_u2be();
    m_data = m__io->read_bytes(len_data());
}

lev_quake_t::resource_0x6c_t::~resource_0x6c_t() {
    _clean_up();
}

void lev_quake_t::resource_0x6c_t::_clean_up() {
}

lev_quake_t::sector_t::sector_t(kaitai::kstream* p__io, lev_quake_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_reserved = 0;
    m_position = 0;
    m_unknown = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::sector_t::_read() {
    m_reserved = new std::vector<uint16_t>();
    const int l_reserved = 2;
    for (int i = 0; i < l_reserved; i++) {
        m_reserved->push_back(m__io->read_u2be());
    }
    m_position = new std::vector<uint16_t>();
    const int l_position = 3;
    for (int i = 0; i < l_position; i++) {
        m_position->push_back(m__io->read_u2be());
    }
    m_distance = m__io->read_u2be();
    m_plane_start_index = m__io->read_u2be();
    m_plane_end_index = m__io->read_u2be();
    m_unknown = new std::vector<uint16_t>();
    const int l_unknown = 6;
    for (int i = 0; i < l_unknown; i++) {
        m_unknown->push_back(m__io->read_u2be());
    }
}

lev_quake_t::sector_t::~sector_t() {
    _clean_up();
}

void lev_quake_t::sector_t::_clean_up() {
    if (m_reserved) {
        delete m_reserved; m_reserved = 0;
    }
    if (m_position) {
        delete m_position; m_position = 0;
    }
    if (m_unknown) {
        delete m_unknown; m_unknown = 0;
    }
}

lev_quake_t::resources_prefix_t::resources_prefix_t(kaitai::kstream* p__io, lev_quake_t::resources_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_values = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::resources_prefix_t::_read() {
    m_num_values = m__io->read_u4be();
    m_values = new std::vector<int16_t>();
    const int l_values = num_values();
    for (int i = 0; i < l_values; i++) {
        m_values->push_back(m__io->read_s2be());
    }
}

lev_quake_t::resources_prefix_t::~resources_prefix_t() {
    _clean_up();
}

void lev_quake_t::resources_prefix_t::_clean_up() {
    if (m_values) {
        delete m_values; m_values = 0;
    }
}

lev_quake_t::sound_t::sound_t(kaitai::kstream* p__io, lev_quake_t::resources_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::sound_t::_read() {
    m_len_samples = m__io->read_s4be();
    m_maybe_pitch_adjust = m__io->read_s4be();
    m_bits = m__io->read_s4be();
    m_loop_point = m__io->read_s4be();
    m_samples = m__io->read_bytes(len_samples());
}

lev_quake_t::sound_t::~sound_t() {
    _clean_up();
}

void lev_quake_t::sound_t::_clean_up() {
}

lev_quake_t::entity_t::entity_t(int32_t p_index, kaitai::kstream* p__io, lev_quake_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_index = p_index;
    f_get_entity_data = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::entity_t::_read() {
    m_ent_type = m__io->read_u2be();
    m_ofs_entity_data = m__io->read_u2be();
}

lev_quake_t::entity_t::~entity_t() {
    _clean_up();
}

void lev_quake_t::entity_t::_clean_up() {
    if (f_get_entity_data && !n_get_entity_data) {
        if (m_get_entity_data) {
            delete m_get_entity_data; m_get_entity_data = 0;
        }
    }
}

kaitai::kstruct* lev_quake_t::entity_t::get_entity_data() {
    if (f_get_entity_data)
        return m_get_entity_data;
    n_get_entity_data = true;
    if (ofs_entity_data() < _root()->header()->len_entity_data()) {
        n_get_entity_data = false;
        kaitai::kstream *io = _root()->entity_data()->_io();
        std::streampos _pos = io->pos();
        io->seek(ofs_entity_data());
        switch (ent_type()) {
        case 146: {
            m_get_entity_data = new entity_polymover_t(io, this, m__root);
            break;
        }
        default: {
            m_get_entity_data = new entity_generic_t(io, this, m__root);
            break;
        }
        }
        io->seek(_pos);
        f_get_entity_data = true;
    }
    return m_get_entity_data;
}

lev_quake_t::resources_t::resources_t(kaitai::kstream* p__io, lev_quake_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_prefix = 0;
    m_sounds = 0;
    m_palette = 0;
    m_resources = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::resources_t::_read() {
    m_prefix = new resources_prefix_t(m__io, this, m__root);
    m_num_sounds = m__io->read_u4be();
    m_sounds = new std::vector<sound_t*>();
    const int l_sounds = num_sounds();
    for (int i = 0; i < l_sounds; i++) {
        m_sounds->push_back(new sound_t(m__io, this, m__root));
    }
    m_len_palette = m__io->read_u4be();
    m_palette = new std::vector<palette_entry_t*>();
    const int l_palette = (len_palette() / 2);
    for (int i = 0; i < l_palette; i++) {
        m_palette->push_back(new palette_entry_t(m__io, this, m__root));
    }
    m_num_resources = m__io->read_u4be();
    m_resources = new std::vector<resource_t*>();
    const int l_resources = num_resources();
    for (int i = 0; i < l_resources; i++) {
        m_resources->push_back(new resource_t(m__io, this, m__root));
    }
}

lev_quake_t::resources_t::~resources_t() {
    _clean_up();
}

void lev_quake_t::resources_t::_clean_up() {
    if (m_prefix) {
        delete m_prefix; m_prefix = 0;
    }
    if (m_sounds) {
        for (std::vector<sound_t*>::iterator it = m_sounds->begin(); it != m_sounds->end(); ++it) {
            delete *it;
        }
        delete m_sounds; m_sounds = 0;
    }
    if (m_palette) {
        for (std::vector<palette_entry_t*>::iterator it = m_palette->begin(); it != m_palette->end(); ++it) {
            delete *it;
        }
        delete m_palette; m_palette = 0;
    }
    if (m_resources) {
        for (std::vector<resource_t*>::iterator it = m_resources->begin(); it != m_resources->end(); ++it) {
            delete *it;
        }
        delete m_resources; m_resources = 0;
    }
}

lev_quake_t::vertex_t::vertex_t(kaitai::kstream* p__io, lev_quake_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_coords = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::vertex_t::_read() {
    m_coords = new std::vector<int16_t>();
    const int l_coords = 3;
    for (int i = 0; i < l_coords; i++) {
        m_coords->push_back(m__io->read_s2be());
    }
    m_color_lookup = m__io->read_u1();
    m_reserved = m__io->read_u1();
}

lev_quake_t::vertex_t::~vertex_t() {
    _clean_up();
}

void lev_quake_t::vertex_t::_clean_up() {
    if (m_coords) {
        delete m_coords; m_coords = 0;
    }
}

lev_quake_t::header_t::header_t(kaitai::kstream* p__io, lev_quake_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::header_t::_read() {
    m_unknown_01 = m__io->read_u4be();
    m_unknown_02 = m__io->read_u4be();
    m_num_sectors = m__io->read_u4be();
    m_num_planes = m__io->read_u4be();
    m_num_vertices = m__io->read_u4be();
    m_num_quads = m__io->read_u4be();
    m_len_tile_texture_data = m__io->read_u4be();
    m_num_tiles = m__io->read_u4be();
    m_len_tile_color_data = m__io->read_u4be();
    m_num_entities = m__io->read_u4be();
    m_len_entity_data = m__io->read_u4be();
    m_num_entity_polylinks = m__io->read_u4be();
    m_num_entity_polylink_data1_segments = m__io->read_u4be();
    m_num_entity_polylink_data2_segments = m__io->read_u4be();
    m_num_unknown = m__io->read_u4be();
}

lev_quake_t::header_t::~header_t() {
    _clean_up();
}

void lev_quake_t::header_t::_clean_up() {
}

lev_quake_t::resource_0x34_t::resource_0x34_t(kaitai::kstream* p__io, lev_quake_t::resource_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_bitmap = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::resource_0x34_t::_read() {
    m_unknown0 = m__io->read_u2be();
    m_bitmap = new std::vector<uint64_t>();
    const int l_bitmap = 1024;
    for (int i = 0; i < l_bitmap; i++) {
        m_bitmap->push_back(m__io->read_bits_int_be(8));
    }
}

lev_quake_t::resource_0x34_t::~resource_0x34_t() {
    _clean_up();
}

void lev_quake_t::resource_0x34_t::_clean_up() {
    if (m_bitmap) {
        delete m_bitmap; m_bitmap = 0;
    }
}

lev_quake_t::entity_polymover_t::entity_polymover_t(kaitai::kstream* p__io, lev_quake_t::entity_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_data = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::entity_polymover_t::_read() {
    m_polylink_id = m__io->read_s2be();
    m_data = new std::vector<int16_t>();
    const int l_data = 20;
    for (int i = 0; i < l_data; i++) {
        m_data->push_back(m__io->read_s2be());
    }
}

lev_quake_t::entity_polymover_t::~entity_polymover_t() {
    _clean_up();
}

void lev_quake_t::entity_polymover_t::_clean_up() {
    if (m_data) {
        delete m_data; m_data = 0;
    }
}

lev_quake_t::len_and_unknown_t::len_and_unknown_t(kaitai::kstream* p__io, lev_quake_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::len_and_unknown_t::_read() {
    m_len_data = m__io->read_u4be();
    m_data = m__io->read_bytes(len_data());
}

lev_quake_t::len_and_unknown_t::~len_and_unknown_t() {
    _clean_up();
}

void lev_quake_t::len_and_unknown_t::_clean_up() {
}

lev_quake_t::quad_t::quad_t(kaitai::kstream* p__io, lev_quake_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_vertex_indices = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::quad_t::_read() {
    m_vertex_indices = new std::vector<uint8_t>();
    const int l_vertex_indices = 4;
    for (int i = 0; i < l_vertex_indices; i++) {
        m_vertex_indices->push_back(m__io->read_u1());
    }
    m_texture_index = m__io->read_u1();
}

lev_quake_t::quad_t::~quad_t() {
    _clean_up();
}

void lev_quake_t::quad_t::_clean_up() {
    if (m_vertex_indices) {
        delete m_vertex_indices; m_vertex_indices = 0;
    }
}

lev_quake_t::texture_t::texture_t(kaitai::kstream* p__io, lev_quake_t::resource_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_palette = 0;
    m_bitmap = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::texture_t::_read() {
    m_palette = new std::vector<palette_entry_t*>();
    const int l_palette = 16;
    for (int i = 0; i < l_palette; i++) {
        m_palette->push_back(new palette_entry_t(m__io, this, m__root));
    }
    m_bitmap = new std::vector<uint64_t>();
    const int l_bitmap = (64 * 64);
    for (int i = 0; i < l_bitmap; i++) {
        m_bitmap->push_back(m__io->read_bits_int_be(4));
    }
}

lev_quake_t::texture_t::~texture_t() {
    _clean_up();
}

void lev_quake_t::texture_t::_clean_up() {
    if (m_palette) {
        for (std::vector<palette_entry_t*>::iterator it = m_palette->begin(); it != m_palette->end(); ++it) {
            delete *it;
        }
        delete m_palette; m_palette = 0;
    }
    if (m_bitmap) {
        delete m_bitmap; m_bitmap = 0;
    }
}

lev_quake_t::palette_entry_t::palette_entry_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::palette_entry_t::_read() {
    m_a = m__io->read_bits_int_be(1);
    m_b = m__io->read_bits_int_be(5);
    m_g = m__io->read_bits_int_be(5);
    m_r = m__io->read_bits_int_be(5);
}

lev_quake_t::palette_entry_t::~palette_entry_t() {
    _clean_up();
}

void lev_quake_t::palette_entry_t::_clean_up() {
}

lev_quake_t::entity_polylink_data1_t::entity_polylink_data1_t(kaitai::kstream* p__io, lev_quake_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_data = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::entity_polylink_data1_t::_read() {
    m_data = new std::vector<uint8_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_data->push_back(m__io->read_u1());
            i++;
        }
    }
}

lev_quake_t::entity_polylink_data1_t::~entity_polylink_data1_t() {
    _clean_up();
}

void lev_quake_t::entity_polylink_data1_t::_clean_up() {
    if (m_data) {
        delete m_data; m_data = 0;
    }
}

lev_quake_t::entity_polylink_data2_t::entity_polylink_data2_t(kaitai::kstream* p__io, lev_quake_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_data = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::entity_polylink_data2_t::_read() {
    m_data = new std::vector<uint8_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_data->push_back(m__io->read_u1());
            i++;
        }
    }
}

lev_quake_t::entity_polylink_data2_t::~entity_polylink_data2_t() {
    _clean_up();
}

void lev_quake_t::entity_polylink_data2_t::_clean_up() {
    if (m_data) {
        delete m_data; m_data = 0;
    }
}

lev_quake_t::resource_t::resource_t(kaitai::kstream* p__io, lev_quake_t::resources_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::resource_t::_read() {
    m_flags = m__io->read_u1();
    m_resource_type = m__io->read_u1();
    n_data = true;
    switch (resource_type()) {
    case 130: {
        n_data = false;
        m_data = new texture_t(m__io, this, m__root);
        break;
    }
    case 52: {
        n_data = false;
        m_data = new resource_0x34_t(m__io, this, m__root);
        break;
    }
    case 106: {
        n_data = false;
        m_data = new resource_0x6a_t(m__io, this, m__root);
        break;
    }
    case 108: {
        n_data = false;
        m_data = new resource_0x6c_t(m__io, this, m__root);
        break;
    }
    }
}

lev_quake_t::resource_t::~resource_t() {
    _clean_up();
}

void lev_quake_t::resource_t::_clean_up() {
    if (!n_data) {
        if (m_data) {
            delete m_data; m_data = 0;
        }
    }
}

lev_quake_t::tile_t::tile_t(kaitai::kstream* p__io, lev_quake_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_horizontal_vector = 0;
    m_vertical_vector = 0;
    m_base_vector = 0;
    m_get_color_data = 0;
    m_get_tile_texture_data = 0;
    f_get_color_data = false;
    f_get_tile_texture_data = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::tile_t::_read() {
    m_ofs_texture_data = m__io->read_u2be();
    m_width = m__io->read_u1();
    m_height = m__io->read_u1();
    m_ofs_color_data = m__io->read_u2be();
    m_unknown = m__io->read_u2be();
    m_horizontal_vector = new std::vector<int32_t>();
    const int l_horizontal_vector = 3;
    for (int i = 0; i < l_horizontal_vector; i++) {
        m_horizontal_vector->push_back(m__io->read_s4be());
    }
    m_vertical_vector = new std::vector<int32_t>();
    const int l_vertical_vector = 3;
    for (int i = 0; i < l_vertical_vector; i++) {
        m_vertical_vector->push_back(m__io->read_s4be());
    }
    m_base_vector = new std::vector<int32_t>();
    const int l_base_vector = 3;
    for (int i = 0; i < l_base_vector; i++) {
        m_base_vector->push_back(m__io->read_s4be());
    }
}

lev_quake_t::tile_t::~tile_t() {
    _clean_up();
}

void lev_quake_t::tile_t::_clean_up() {
    if (m_horizontal_vector) {
        delete m_horizontal_vector; m_horizontal_vector = 0;
    }
    if (m_vertical_vector) {
        delete m_vertical_vector; m_vertical_vector = 0;
    }
    if (m_base_vector) {
        delete m_base_vector; m_base_vector = 0;
    }
    if (f_get_color_data) {
        if (m_get_color_data) {
            delete m_get_color_data; m_get_color_data = 0;
        }
    }
    if (f_get_tile_texture_data) {
        if (m_get_tile_texture_data) {
            delete m_get_tile_texture_data; m_get_tile_texture_data = 0;
        }
    }
}

std::vector<uint8_t>* lev_quake_t::tile_t::get_color_data() {
    if (f_get_color_data)
        return m_get_color_data;
    kaitai::kstream *io = _root()->tile_color_data()->_io();
    std::streampos _pos = io->pos();
    io->seek(ofs_color_data());
    m_get_color_data = new std::vector<uint8_t>();
    const int l_get_color_data = ((width() + 1) * (height() + 1));
    for (int i = 0; i < l_get_color_data; i++) {
        m_get_color_data->push_back(io->read_u1());
    }
    io->seek(_pos);
    f_get_color_data = true;
    return m_get_color_data;
}

std::vector<uint8_t>* lev_quake_t::tile_t::get_tile_texture_data() {
    if (f_get_tile_texture_data)
        return m_get_tile_texture_data;
    kaitai::kstream *io = _root()->tile_texture_data()->_io();
    std::streampos _pos = io->pos();
    io->seek(ofs_texture_data());
    m_get_tile_texture_data = new std::vector<uint8_t>();
    const int l_get_tile_texture_data = ((height() * width()) * 2);
    for (int i = 0; i < l_get_tile_texture_data; i++) {
        m_get_tile_texture_data->push_back(io->read_u1());
    }
    io->seek(_pos);
    f_get_tile_texture_data = true;
    return m_get_tile_texture_data;
}

lev_quake_t::entity_polylink_t::entity_polylink_t(kaitai::kstream* p__io, lev_quake_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_ofs_entity_polylink_data1 = 0;
    m_ofs_entity_polylink_data2 = 0;
    m_reserved = 0;
    m_getdata1 = 0;
    m_getdata2 = 0;
    f_getdata1 = false;
    f_getdata2 = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::entity_polylink_t::_read() {
    m_lead = m__io->read_u2be();
    m_ofs_entity_polylink_data1 = new std::vector<uint16_t>();
    const int l_ofs_entity_polylink_data1 = 2;
    for (int i = 0; i < l_ofs_entity_polylink_data1; i++) {
        m_ofs_entity_polylink_data1->push_back(m__io->read_u2be());
    }
    m_ofs_entity_polylink_data2 = new std::vector<uint16_t>();
    const int l_ofs_entity_polylink_data2 = 2;
    for (int i = 0; i < l_ofs_entity_polylink_data2; i++) {
        m_ofs_entity_polylink_data2->push_back(m__io->read_u2be());
    }
    m_unknown = m__io->read_u2be();
    m_reserved = new std::vector<uint16_t>();
    const int l_reserved = 3;
    for (int i = 0; i < l_reserved; i++) {
        m_reserved->push_back(m__io->read_u2be());
    }
}

lev_quake_t::entity_polylink_t::~entity_polylink_t() {
    _clean_up();
}

void lev_quake_t::entity_polylink_t::_clean_up() {
    if (m_ofs_entity_polylink_data1) {
        delete m_ofs_entity_polylink_data1; m_ofs_entity_polylink_data1 = 0;
    }
    if (m_ofs_entity_polylink_data2) {
        delete m_ofs_entity_polylink_data2; m_ofs_entity_polylink_data2 = 0;
    }
    if (m_reserved) {
        delete m_reserved; m_reserved = 0;
    }
    if (f_getdata1) {
        if (m_getdata1) {
            delete m_getdata1; m_getdata1 = 0;
        }
    }
    if (f_getdata2) {
        if (m_getdata2) {
            delete m_getdata2; m_getdata2 = 0;
        }
    }
}

std::vector<uint8_t>* lev_quake_t::entity_polylink_t::getdata1() {
    if (f_getdata1)
        return m_getdata1;
    kaitai::kstream *io = _root()->entity_polylink_data1()->_io();
    std::streampos _pos = io->pos();
    io->seek((ofs_entity_polylink_data1()->at(0) * 2));
    m_getdata1 = new std::vector<uint8_t>();
    const int l_getdata1 = (((ofs_entity_polylink_data1()->at(1) - ofs_entity_polylink_data1()->at(0)) + 1) * 2);
    for (int i = 0; i < l_getdata1; i++) {
        m_getdata1->push_back(io->read_u1());
    }
    io->seek(_pos);
    f_getdata1 = true;
    return m_getdata1;
}

std::vector<uint8_t>* lev_quake_t::entity_polylink_t::getdata2() {
    if (f_getdata2)
        return m_getdata2;
    kaitai::kstream *io = _root()->entity_polylink_data2()->_io();
    std::streampos _pos = io->pos();
    io->seek((ofs_entity_polylink_data2()->at(0) * 4));
    m_getdata2 = new std::vector<uint8_t>();
    const int l_getdata2 = (((ofs_entity_polylink_data2()->at(1) - ofs_entity_polylink_data2()->at(0)) + 1) * 4);
    for (int i = 0; i < l_getdata2; i++) {
        m_getdata2->push_back(io->read_u1());
    }
    io->seek(_pos);
    f_getdata2 = true;
    return m_getdata2;
}

lev_quake_t::plane_t::plane_t(kaitai::kstream* p__io, lev_quake_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_vertex_indices = 0;
    m_normal = 0;
    m_reserved = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::plane_t::_read() {
    m_vertex_indices = new std::vector<uint16_t>();
    const int l_vertex_indices = 4;
    for (int i = 0; i < l_vertex_indices; i++) {
        m_vertex_indices->push_back(m__io->read_u2be());
    }
    m_sector_index = m__io->read_u2be();
    m_flags = m__io->read_u2be();
    m_collision_flags = m__io->read_u2be();
    m_tile_index = m__io->read_u2be();
    m_unknown_index = m__io->read_u2be();
    m_quad_start_index = m__io->read_u2be();
    m_quad_end_index = m__io->read_u2be();
    m_vertex_start_index = m__io->read_u2be();
    m_vertex_end_index = m__io->read_u2be();
    m_normal = new std::vector<int16_t>();
    const int l_normal = 3;
    for (int i = 0; i < l_normal; i++) {
        m_normal->push_back(m__io->read_s2be());
    }
    m_distance = m__io->read_s2be();
    m_angle = m__io->read_s2be();
    m_reserved = new std::vector<uint16_t>();
    const int l_reserved = 2;
    for (int i = 0; i < l_reserved; i++) {
        m_reserved->push_back(m__io->read_u2be());
    }
}

lev_quake_t::plane_t::~plane_t() {
    _clean_up();
}

void lev_quake_t::plane_t::_clean_up() {
    if (m_vertex_indices) {
        delete m_vertex_indices; m_vertex_indices = 0;
    }
    if (m_normal) {
        delete m_normal; m_normal = 0;
    }
    if (m_reserved) {
        delete m_reserved; m_reserved = 0;
    }
}

lev_quake_t::sky_bitmap_t::sky_bitmap_t(kaitai::kstream* p__io, lev_quake_t::sky_data_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::sky_bitmap_t::_read() {
    m_image = m__io->read_bytes(2048);
}

lev_quake_t::sky_bitmap_t::~sky_bitmap_t() {
    _clean_up();
}

void lev_quake_t::sky_bitmap_t::_clean_up() {
}

lev_quake_t::entity_generic_t::entity_generic_t(kaitai::kstream* p__io, lev_quake_t::entity_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_coords = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::entity_generic_t::_read() {
    m_start = m__io->read_s2be();
    m_coords = new std::vector<int16_t>();
    const int l_coords = 3;
    for (int i = 0; i < l_coords; i++) {
        m_coords->push_back(m__io->read_s2be());
    }
}

lev_quake_t::entity_generic_t::~entity_generic_t() {
    _clean_up();
}

void lev_quake_t::entity_generic_t::_clean_up() {
    if (m_coords) {
        delete m_coords; m_coords = 0;
    }
}

lev_quake_t::resource_0x6a_t::resource_0x6a_t(kaitai::kstream* p__io, lev_quake_t::resource_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::resource_0x6a_t::_read() {
    m_unknown0 = m__io->read_u2be();
    m_len_data = m__io->read_u2be();
    m_data = m__io->read_bytes(len_data());
}

lev_quake_t::resource_0x6a_t::~resource_0x6a_t() {
    _clean_up();
}

void lev_quake_t::resource_0x6a_t::_clean_up() {
}

lev_quake_t::sky_data_t::sky_data_t(kaitai::kstream* p__io, lev_quake_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_palette = 0;
    m_bitmaps = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::sky_data_t::_read() {
    m_palette = new std::vector<palette_entry_t*>();
    const int l_palette = 16;
    for (int i = 0; i < l_palette; i++) {
        m_palette->push_back(new palette_entry_t(m__io, this, m__root));
    }
    m_bitmaps = new std::vector<sky_bitmap_t*>();
    const int l_bitmaps = 64;
    for (int i = 0; i < l_bitmaps; i++) {
        m_bitmaps->push_back(new sky_bitmap_t(m__io, this, m__root));
    }
}

lev_quake_t::sky_data_t::~sky_data_t() {
    _clean_up();
}

void lev_quake_t::sky_data_t::_clean_up() {
    if (m_palette) {
        for (std::vector<palette_entry_t*>::iterator it = m_palette->begin(); it != m_palette->end(); ++it) {
            delete *it;
        }
        delete m_palette; m_palette = 0;
    }
    if (m_bitmaps) {
        for (std::vector<sky_bitmap_t*>::iterator it = m_bitmaps->begin(); it != m_bitmaps->end(); ++it) {
            delete *it;
        }
        delete m_bitmaps; m_bitmaps = 0;
    }
}

lev_quake_t::tile_color_data_t::tile_color_data_t(kaitai::kstream* p__io, lev_quake_t* p__parent, lev_quake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lev_quake_t::tile_color_data_t::_read() {
    m_data = m__io->read_bytes(_parent()->header()->len_tile_color_data());
}

lev_quake_t::tile_color_data_t::~tile_color_data_t() {
    _clean_up();
}

void lev_quake_t::tile_color_data_t::_clean_up() {
}
