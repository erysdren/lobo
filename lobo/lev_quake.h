#ifndef LEV_QUAKE_H_
#define LEV_QUAKE_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

/**
 * Level format used by Sega Saturn Quake, created by Lobotomy Software.
 * Contains level mesh information, entities, textures, sounds, and other game data.
 * 
 * Origin of this file: https://github.com/erysdren/Formats
 */

class lev_quake_t : public kaitai::kstruct {

public:
    class tile_texture_data_t;
    class entity_data_t;
    class resource_0x6c_t;
    class sector_t;
    class resources_prefix_t;
    class sound_t;
    class entity_t;
    class resources_t;
    class vertex_t;
    class header_t;
    class resource_0x34_t;
    class entity_polymover_t;
    class len_and_unknown_t;
    class quad_t;
    class texture_t;
    class palette_entry_t;
    class entity_polylink_data1_t;
    class entity_polylink_data2_t;
    class resource_t;
    class tile_t;
    class entity_polylink_t;
    class plane_t;
    class sky_bitmap_t;
    class entity_generic_t;
    class resource_0x6a_t;
    class sky_data_t;
    class tile_color_data_t;

    lev_quake_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, lev_quake_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~lev_quake_t();

    class tile_texture_data_t : public kaitai::kstruct {

    public:

        tile_texture_data_t(kaitai::kstream* p__io, lev_quake_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~tile_texture_data_t();

    private:
        std::string m_data;
        lev_quake_t* m__root;
        lev_quake_t* m__parent;

    public:
        std::string data() const { return m_data; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t* _parent() const { return m__parent; }
    };

    class entity_data_t : public kaitai::kstruct {

    public:

        entity_data_t(kaitai::kstream* p__io, lev_quake_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~entity_data_t();

    private:
        std::string m_data;
        lev_quake_t* m__root;
        lev_quake_t* m__parent;

    public:
        std::string data() const { return m_data; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t* _parent() const { return m__parent; }
    };

    class resource_0x6c_t : public kaitai::kstruct {

    public:

        resource_0x6c_t(kaitai::kstream* p__io, lev_quake_t::resource_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~resource_0x6c_t();

    private:
        uint16_t m_unknown0;
        uint16_t m_len_data;
        std::string m_data;
        lev_quake_t* m__root;
        lev_quake_t::resource_t* m__parent;

    public:
        uint16_t unknown0() const { return m_unknown0; }
        uint16_t len_data() const { return m_len_data; }
        std::string data() const { return m_data; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t::resource_t* _parent() const { return m__parent; }
    };

    class sector_t : public kaitai::kstruct {

    public:

        sector_t(kaitai::kstream* p__io, lev_quake_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~sector_t();

    private:
        std::vector<uint16_t>* m_reserved;
        std::vector<uint16_t>* m_position;
        uint16_t m_distance;
        uint16_t m_plane_start_index;
        uint16_t m_plane_end_index;
        std::vector<uint16_t>* m_unknown;
        lev_quake_t* m__root;
        lev_quake_t* m__parent;

    public:
        std::vector<uint16_t>* reserved() const { return m_reserved; }
        std::vector<uint16_t>* position() const { return m_position; }
        uint16_t distance() const { return m_distance; }
        uint16_t plane_start_index() const { return m_plane_start_index; }
        uint16_t plane_end_index() const { return m_plane_end_index; }
        std::vector<uint16_t>* unknown() const { return m_unknown; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t* _parent() const { return m__parent; }
    };

    class resources_prefix_t : public kaitai::kstruct {

    public:

        resources_prefix_t(kaitai::kstream* p__io, lev_quake_t::resources_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~resources_prefix_t();

    private:
        uint32_t m_num_values;
        std::vector<int16_t>* m_values;
        lev_quake_t* m__root;
        lev_quake_t::resources_t* m__parent;

    public:
        uint32_t num_values() const { return m_num_values; }
        std::vector<int16_t>* values() const { return m_values; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t::resources_t* _parent() const { return m__parent; }
    };

    class sound_t : public kaitai::kstruct {

    public:

        sound_t(kaitai::kstream* p__io, lev_quake_t::resources_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~sound_t();

    private:
        int32_t m_len_samples;
        int32_t m_maybe_pitch_adjust;
        int32_t m_bits;
        int32_t m_loop_point;
        std::string m_samples;
        lev_quake_t* m__root;
        lev_quake_t::resources_t* m__parent;

    public:
        int32_t len_samples() const { return m_len_samples; }

        /**
         * from comparing the extracted sounds with the sounds in the game
         * (see https://www.youtube.com/watch?v=Wse8iFMM-jg&t=207s and E1L1.LEV
         * sound 0), i think this is a speed/pitch adjust. 0x7000 seems to be
         * the nominal value, with sounds with that value sounding the same. but
         * notably door and elevator sound pitches sound different in game, and
         * they have a different value here. however, i havent managed to find
         * a consistent correlation between these values and the pitch change.
         * -- vfig
         */
        int32_t maybe_pitch_adjust() const { return m_maybe_pitch_adjust; }

        /**
         * bits per sample; 8 or 16.
         */
        int32_t bits() const { return m_bits; }

        /**
         * index of sample (or possibly byte offset; with 8 bit sounds its the
         * same) from which to loop after reaching the end of the sound the
         * first time. 0 means the entire sample loops; -1 means no loop.
         */
        int32_t loop_point() const { return m_loop_point; }
        std::string samples() const { return m_samples; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t::resources_t* _parent() const { return m__parent; }
    };

    class entity_t : public kaitai::kstruct {

    public:

        entity_t(int32_t p_index, kaitai::kstream* p__io, lev_quake_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~entity_t();

    private:
        bool f_get_entity_data;
        kaitai::kstruct* m_get_entity_data;
        bool n_get_entity_data;

    public:
        bool _is_null_get_entity_data() { get_entity_data(); return n_get_entity_data; };

    private:

    public:
        kaitai::kstruct* get_entity_data();

    private:
        uint16_t m_ent_type;
        uint16_t m_ofs_entity_data;
        int32_t m_index;
        lev_quake_t* m__root;
        lev_quake_t* m__parent;

    public:
        uint16_t ent_type() const { return m_ent_type; }
        uint16_t ofs_entity_data() const { return m_ofs_entity_data; }
        int32_t index() const { return m_index; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t* _parent() const { return m__parent; }
    };

    class resources_t : public kaitai::kstruct {

    public:

        resources_t(kaitai::kstream* p__io, lev_quake_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~resources_t();

    private:
        resources_prefix_t* m_prefix;
        uint32_t m_num_sounds;
        std::vector<sound_t*>* m_sounds;
        uint32_t m_len_palette;
        std::vector<palette_entry_t*>* m_palette;
        uint32_t m_num_resources;
        std::vector<resource_t*>* m_resources;
        lev_quake_t* m__root;
        lev_quake_t* m__parent;

    public:
        resources_prefix_t* prefix() const { return m_prefix; }
        uint32_t num_sounds() const { return m_num_sounds; }
        std::vector<sound_t*>* sounds() const { return m_sounds; }
        uint32_t len_palette() const { return m_len_palette; }
        std::vector<palette_entry_t*>* palette() const { return m_palette; }
        uint32_t num_resources() const { return m_num_resources; }
        std::vector<resource_t*>* resources() const { return m_resources; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t* _parent() const { return m__parent; }
    };

    class vertex_t : public kaitai::kstruct {

    public:

        vertex_t(kaitai::kstream* p__io, lev_quake_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~vertex_t();

    private:
        std::vector<int16_t>* m_coords;
        uint8_t m_color_lookup;
        uint8_t m_reserved;
        lev_quake_t* m__root;
        lev_quake_t* m__parent;

    public:
        std::vector<int16_t>* coords() const { return m_coords; }
        uint8_t color_lookup() const { return m_color_lookup; }
        uint8_t reserved() const { return m_reserved; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t* _parent() const { return m__parent; }
    };

    class header_t : public kaitai::kstruct {

    public:

        header_t(kaitai::kstream* p__io, lev_quake_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~header_t();

    private:
        uint32_t m_unknown_01;
        uint32_t m_unknown_02;
        uint32_t m_num_sectors;
        uint32_t m_num_planes;
        uint32_t m_num_vertices;
        uint32_t m_num_quads;
        uint32_t m_len_tile_texture_data;
        uint32_t m_num_tiles;
        uint32_t m_len_tile_color_data;
        uint32_t m_num_entities;
        uint32_t m_len_entity_data;
        uint32_t m_num_entity_polylinks;
        uint32_t m_num_entity_polylink_data1_segments;
        uint32_t m_num_entity_polylink_data2_segments;
        uint32_t m_num_unknown;
        lev_quake_t* m__root;
        lev_quake_t* m__parent;

    public:
        uint32_t unknown_01() const { return m_unknown_01; }
        uint32_t unknown_02() const { return m_unknown_02; }
        uint32_t num_sectors() const { return m_num_sectors; }
        uint32_t num_planes() const { return m_num_planes; }
        uint32_t num_vertices() const { return m_num_vertices; }
        uint32_t num_quads() const { return m_num_quads; }
        uint32_t len_tile_texture_data() const { return m_len_tile_texture_data; }
        uint32_t num_tiles() const { return m_num_tiles; }
        uint32_t len_tile_color_data() const { return m_len_tile_color_data; }
        uint32_t num_entities() const { return m_num_entities; }
        uint32_t len_entity_data() const { return m_len_entity_data; }
        uint32_t num_entity_polylinks() const { return m_num_entity_polylinks; }
        uint32_t num_entity_polylink_data1_segments() const { return m_num_entity_polylink_data1_segments; }
        uint32_t num_entity_polylink_data2_segments() const { return m_num_entity_polylink_data2_segments; }
        uint32_t num_unknown() const { return m_num_unknown; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t* _parent() const { return m__parent; }
    };

    class resource_0x34_t : public kaitai::kstruct {

    public:

        resource_0x34_t(kaitai::kstream* p__io, lev_quake_t::resource_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~resource_0x34_t();

    private:
        uint16_t m_unknown0;
        std::vector<uint64_t>* m_bitmap;
        lev_quake_t* m__root;
        lev_quake_t::resource_t* m__parent;

    public:
        uint16_t unknown0() const { return m_unknown0; }
        std::vector<uint64_t>* bitmap() const { return m_bitmap; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t::resource_t* _parent() const { return m__parent; }
    };

    class entity_polymover_t : public kaitai::kstruct {

    public:

        entity_polymover_t(kaitai::kstream* p__io, lev_quake_t::entity_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~entity_polymover_t();

    private:
        int16_t m_polylink_id;
        std::vector<int16_t>* m_data;
        lev_quake_t* m__root;
        lev_quake_t::entity_t* m__parent;

    public:
        int16_t polylink_id() const { return m_polylink_id; }
        std::vector<int16_t>* data() const { return m_data; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t::entity_t* _parent() const { return m__parent; }
    };

    class len_and_unknown_t : public kaitai::kstruct {

    public:

        len_and_unknown_t(kaitai::kstream* p__io, lev_quake_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~len_and_unknown_t();

    private:
        uint32_t m_len_data;
        std::string m_data;
        lev_quake_t* m__root;
        lev_quake_t* m__parent;

    public:
        uint32_t len_data() const { return m_len_data; }
        std::string data() const { return m_data; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t* _parent() const { return m__parent; }
    };

    class quad_t : public kaitai::kstruct {

    public:

        quad_t(kaitai::kstream* p__io, lev_quake_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~quad_t();

    private:
        std::vector<uint8_t>* m_vertex_indices;
        uint8_t m_texture_index;
        lev_quake_t* m__root;
        lev_quake_t* m__parent;

    public:
        std::vector<uint8_t>* vertex_indices() const { return m_vertex_indices; }
        uint8_t texture_index() const { return m_texture_index; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t* _parent() const { return m__parent; }
    };

    class texture_t : public kaitai::kstruct {

    public:

        texture_t(kaitai::kstream* p__io, lev_quake_t::resource_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~texture_t();

    private:
        std::vector<palette_entry_t*>* m_palette;
        std::vector<uint64_t>* m_bitmap;
        lev_quake_t* m__root;
        lev_quake_t::resource_t* m__parent;

    public:
        std::vector<palette_entry_t*>* palette() const { return m_palette; }
        std::vector<uint64_t>* bitmap() const { return m_bitmap; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t::resource_t* _parent() const { return m__parent; }
    };

    class palette_entry_t : public kaitai::kstruct {

    public:

        palette_entry_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~palette_entry_t();

    private:
        bool m_a;
        uint64_t m_b;
        uint64_t m_g;
        uint64_t m_r;
        lev_quake_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        bool a() const { return m_a; }
        uint64_t b() const { return m_b; }
        uint64_t g() const { return m_g; }
        uint64_t r() const { return m_r; }
        lev_quake_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class entity_polylink_data1_t : public kaitai::kstruct {

    public:

        entity_polylink_data1_t(kaitai::kstream* p__io, lev_quake_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~entity_polylink_data1_t();

    private:
        std::vector<uint8_t>* m_data;
        lev_quake_t* m__root;
        lev_quake_t* m__parent;

    public:
        std::vector<uint8_t>* data() const { return m_data; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t* _parent() const { return m__parent; }
    };

    class entity_polylink_data2_t : public kaitai::kstruct {

    public:

        entity_polylink_data2_t(kaitai::kstream* p__io, lev_quake_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~entity_polylink_data2_t();

    private:
        std::vector<uint8_t>* m_data;
        lev_quake_t* m__root;
        lev_quake_t* m__parent;

    public:
        std::vector<uint8_t>* data() const { return m_data; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t* _parent() const { return m__parent; }
    };

    class resource_t : public kaitai::kstruct {

    public:

        resource_t(kaitai::kstream* p__io, lev_quake_t::resources_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~resource_t();

    private:
        uint8_t m_flags;
        uint8_t m_resource_type;
        kaitai::kstruct* m_data;
        bool n_data;

    public:
        bool _is_null_data() { data(); return n_data; };

    private:
        lev_quake_t* m__root;
        lev_quake_t::resources_t* m__parent;

    public:
        uint8_t flags() const { return m_flags; }
        uint8_t resource_type() const { return m_resource_type; }
        kaitai::kstruct* data() const { return m_data; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t::resources_t* _parent() const { return m__parent; }
    };

    class tile_t : public kaitai::kstruct {

    public:

        tile_t(kaitai::kstream* p__io, lev_quake_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~tile_t();

    private:
        bool f_get_color_data;
        std::vector<uint8_t>* m_get_color_data;

    public:
        std::vector<uint8_t>* get_color_data();

    private:
        bool f_get_tile_texture_data;
        std::vector<uint8_t>* m_get_tile_texture_data;

    public:
        std::vector<uint8_t>* get_tile_texture_data();

    private:
        uint16_t m_ofs_texture_data;
        uint8_t m_width;
        uint8_t m_height;
        uint16_t m_ofs_color_data;
        uint16_t m_unknown;
        std::vector<int32_t>* m_horizontal_vector;
        std::vector<int32_t>* m_vertical_vector;
        std::vector<int32_t>* m_base_vector;
        lev_quake_t* m__root;
        lev_quake_t* m__parent;

    public:
        uint16_t ofs_texture_data() const { return m_ofs_texture_data; }
        uint8_t width() const { return m_width; }
        uint8_t height() const { return m_height; }
        uint16_t ofs_color_data() const { return m_ofs_color_data; }
        uint16_t unknown() const { return m_unknown; }
        std::vector<int32_t>* horizontal_vector() const { return m_horizontal_vector; }
        std::vector<int32_t>* vertical_vector() const { return m_vertical_vector; }
        std::vector<int32_t>* base_vector() const { return m_base_vector; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t* _parent() const { return m__parent; }
    };

    class entity_polylink_t : public kaitai::kstruct {

    public:

        entity_polylink_t(kaitai::kstream* p__io, lev_quake_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~entity_polylink_t();

    private:
        bool f_getdata1;
        std::vector<uint8_t>* m_getdata1;

    public:
        std::vector<uint8_t>* getdata1();

    private:
        bool f_getdata2;
        std::vector<uint8_t>* m_getdata2;

    public:
        std::vector<uint8_t>* getdata2();

    private:
        uint16_t m_lead;
        std::vector<uint16_t>* m_ofs_entity_polylink_data1;
        std::vector<uint16_t>* m_ofs_entity_polylink_data2;
        uint16_t m_unknown;
        std::vector<uint16_t>* m_reserved;
        lev_quake_t* m__root;
        lev_quake_t* m__parent;

    public:
        uint16_t lead() const { return m_lead; }
        std::vector<uint16_t>* ofs_entity_polylink_data1() const { return m_ofs_entity_polylink_data1; }
        std::vector<uint16_t>* ofs_entity_polylink_data2() const { return m_ofs_entity_polylink_data2; }
        uint16_t unknown() const { return m_unknown; }
        std::vector<uint16_t>* reserved() const { return m_reserved; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t* _parent() const { return m__parent; }
    };

    class plane_t : public kaitai::kstruct {

    public:

        plane_t(kaitai::kstream* p__io, lev_quake_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~plane_t();

    private:
        std::vector<uint16_t>* m_vertex_indices;
        uint16_t m_sector_index;
        uint16_t m_flags;
        uint16_t m_collision_flags;
        uint16_t m_tile_index;
        uint16_t m_unknown_index;
        uint16_t m_quad_start_index;
        uint16_t m_quad_end_index;
        uint16_t m_vertex_start_index;
        uint16_t m_vertex_end_index;
        std::vector<int16_t>* m_normal;
        int16_t m_distance;
        int16_t m_angle;
        std::vector<uint16_t>* m_reserved;
        lev_quake_t* m__root;
        lev_quake_t* m__parent;

    public:
        std::vector<uint16_t>* vertex_indices() const { return m_vertex_indices; }
        uint16_t sector_index() const { return m_sector_index; }
        uint16_t flags() const { return m_flags; }
        uint16_t collision_flags() const { return m_collision_flags; }
        uint16_t tile_index() const { return m_tile_index; }
        uint16_t unknown_index() const { return m_unknown_index; }
        uint16_t quad_start_index() const { return m_quad_start_index; }
        uint16_t quad_end_index() const { return m_quad_end_index; }
        uint16_t vertex_start_index() const { return m_vertex_start_index; }
        uint16_t vertex_end_index() const { return m_vertex_end_index; }
        std::vector<int16_t>* normal() const { return m_normal; }
        int16_t distance() const { return m_distance; }
        int16_t angle() const { return m_angle; }
        std::vector<uint16_t>* reserved() const { return m_reserved; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t* _parent() const { return m__parent; }
    };

    class sky_bitmap_t : public kaitai::kstruct {

    public:

        sky_bitmap_t(kaitai::kstream* p__io, lev_quake_t::sky_data_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~sky_bitmap_t();

    private:
        std::string m_image;
        lev_quake_t* m__root;
        lev_quake_t::sky_data_t* m__parent;

    public:
        std::string image() const { return m_image; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t::sky_data_t* _parent() const { return m__parent; }
    };

    class entity_generic_t : public kaitai::kstruct {

    public:

        entity_generic_t(kaitai::kstream* p__io, lev_quake_t::entity_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~entity_generic_t();

    private:
        int16_t m_start;
        std::vector<int16_t>* m_coords;
        lev_quake_t* m__root;
        lev_quake_t::entity_t* m__parent;

    public:
        int16_t start() const { return m_start; }
        std::vector<int16_t>* coords() const { return m_coords; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t::entity_t* _parent() const { return m__parent; }
    };

    class resource_0x6a_t : public kaitai::kstruct {

    public:

        resource_0x6a_t(kaitai::kstream* p__io, lev_quake_t::resource_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~resource_0x6a_t();

    private:
        uint16_t m_unknown0;
        uint16_t m_len_data;
        std::string m_data;
        lev_quake_t* m__root;
        lev_quake_t::resource_t* m__parent;

    public:
        uint16_t unknown0() const { return m_unknown0; }
        uint16_t len_data() const { return m_len_data; }
        std::string data() const { return m_data; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t::resource_t* _parent() const { return m__parent; }
    };

    class sky_data_t : public kaitai::kstruct {

    public:

        sky_data_t(kaitai::kstream* p__io, lev_quake_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~sky_data_t();

    private:
        std::vector<palette_entry_t*>* m_palette;
        std::vector<sky_bitmap_t*>* m_bitmaps;
        lev_quake_t* m__root;
        lev_quake_t* m__parent;

    public:
        std::vector<palette_entry_t*>* palette() const { return m_palette; }
        std::vector<sky_bitmap_t*>* bitmaps() const { return m_bitmaps; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t* _parent() const { return m__parent; }
    };

    class tile_color_data_t : public kaitai::kstruct {

    public:

        tile_color_data_t(kaitai::kstream* p__io, lev_quake_t* p__parent = 0, lev_quake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~tile_color_data_t();

    private:
        std::string m_data;
        lev_quake_t* m__root;
        lev_quake_t* m__parent;

    public:
        std::string data() const { return m_data; }
        lev_quake_t* _root() const { return m__root; }
        lev_quake_t* _parent() const { return m__parent; }
    };

private:
    sky_data_t* m_sky_data;
    header_t* m_header;
    std::vector<sector_t*>* m_sectors;
    std::vector<plane_t*>* m_planes;
    std::vector<tile_t*>* m_tiles;
    std::vector<vertex_t*>* m_vertices;
    std::vector<quad_t*>* m_quads;
    std::vector<entity_t*>* m_entities;
    std::vector<entity_polylink_t*>* m_entity_polylinks;
    entity_polylink_data1_t* m_entity_polylink_data1;
    entity_polylink_data2_t* m_entity_polylink_data2;
    entity_data_t* m_entity_data;
    tile_texture_data_t* m_tile_texture_data;
    tile_color_data_t* m_tile_color_data;
    std::vector<std::string>* m_unknown;
    resources_t* m_resources;
    len_and_unknown_t* m_unknown0;
    std::string m_level_name;
    std::vector<uint32_t>* m_unknown1;
    len_and_unknown_t* m_unknown2;
    len_and_unknown_t* m_unknown3;
    lev_quake_t* m__root;
    kaitai::kstruct* m__parent;
    std::string m__raw_sky_data;
    kaitai::kstream* m__io__raw_sky_data;
    std::string m__raw_entity_polylink_data1;
    kaitai::kstream* m__io__raw_entity_polylink_data1;
    std::string m__raw_entity_polylink_data2;
    kaitai::kstream* m__io__raw_entity_polylink_data2;
    std::string m__raw_entity_data;
    kaitai::kstream* m__io__raw_entity_data;
    std::string m__raw_tile_texture_data;
    kaitai::kstream* m__io__raw_tile_texture_data;
    std::string m__raw_tile_color_data;
    kaitai::kstream* m__io__raw_tile_color_data;

public:
    sky_data_t* sky_data() const { return m_sky_data; }
    header_t* header() const { return m_header; }
    std::vector<sector_t*>* sectors() const { return m_sectors; }
    std::vector<plane_t*>* planes() const { return m_planes; }
    std::vector<tile_t*>* tiles() const { return m_tiles; }
    std::vector<vertex_t*>* vertices() const { return m_vertices; }
    std::vector<quad_t*>* quads() const { return m_quads; }
    std::vector<entity_t*>* entities() const { return m_entities; }
    std::vector<entity_polylink_t*>* entity_polylinks() const { return m_entity_polylinks; }
    entity_polylink_data1_t* entity_polylink_data1() const { return m_entity_polylink_data1; }
    entity_polylink_data2_t* entity_polylink_data2() const { return m_entity_polylink_data2; }
    entity_data_t* entity_data() const { return m_entity_data; }
    tile_texture_data_t* tile_texture_data() const { return m_tile_texture_data; }
    tile_color_data_t* tile_color_data() const { return m_tile_color_data; }
    std::vector<std::string>* unknown() const { return m_unknown; }
    resources_t* resources() const { return m_resources; }
    len_and_unknown_t* unknown0() const { return m_unknown0; }
    std::string level_name() const { return m_level_name; }
    std::vector<uint32_t>* unknown1() const { return m_unknown1; }
    len_and_unknown_t* unknown2() const { return m_unknown2; }
    len_and_unknown_t* unknown3() const { return m_unknown3; }
    lev_quake_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
    std::string _raw_sky_data() const { return m__raw_sky_data; }
    kaitai::kstream* _io__raw_sky_data() const { return m__io__raw_sky_data; }
    std::string _raw_entity_polylink_data1() const { return m__raw_entity_polylink_data1; }
    kaitai::kstream* _io__raw_entity_polylink_data1() const { return m__io__raw_entity_polylink_data1; }
    std::string _raw_entity_polylink_data2() const { return m__raw_entity_polylink_data2; }
    kaitai::kstream* _io__raw_entity_polylink_data2() const { return m__io__raw_entity_polylink_data2; }
    std::string _raw_entity_data() const { return m__raw_entity_data; }
    kaitai::kstream* _io__raw_entity_data() const { return m__io__raw_entity_data; }
    std::string _raw_tile_texture_data() const { return m__raw_tile_texture_data; }
    kaitai::kstream* _io__raw_tile_texture_data() const { return m__io__raw_tile_texture_data; }
    std::string _raw_tile_color_data() const { return m__raw_tile_color_data; }
    kaitai::kstream* _io__raw_tile_color_data() const { return m__io__raw_tile_color_data; }
};

#endif  // LEV_QUAKE_H_
