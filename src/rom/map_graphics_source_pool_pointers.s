; Numeric source-pool pointers; bank bits are ORed with $C0 by the loader.
.setcpu "65816"
map_graphics_2bpp_pool = $1FE7E0
map_graphics_3bpp_pool = $1F6000
map_graphics_4bpp_pool = $1C0000
map_graphics_64byte_pool = $1D0000
.segment "CODE"
.org $E270
map_graphics_source_pool_pointers:
    .faraddr map_graphics_2bpp_pool
    .faraddr map_graphics_3bpp_pool
    .faraddr map_graphics_4bpp_pool
    .faraddr map_graphics_64byte_pool
