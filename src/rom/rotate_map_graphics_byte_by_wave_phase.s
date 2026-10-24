; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B6E9
rotate_map_graphics_byte_by_wave_phase:
    sta $00
    .i8
    cpx #$08
    bcs rotate_map_graphics_byte_by_wave_phase_c1b70d
    .i8
    cpx #$00
    beq rotate_map_graphics_byte_by_wave_phase_c1b70c
    .i8
    cpx #$01
    bne rotate_map_graphics_byte_by_wave_phase_c1b6fb
rotate_map_graphics_byte_by_wave_phase_c1b6f7:
    lsr $00
    ror
    rts
rotate_map_graphics_byte_by_wave_phase_c1b6fb:
    .i8
    cpx #$07
    beq rotate_map_graphics_byte_by_wave_phase_c1b6f7
    .i8
    cpx #$04
    bne rotate_map_graphics_byte_by_wave_phase_c1b706
    lsr $00
    ror
rotate_map_graphics_byte_by_wave_phase_c1b706:
    lsr $00
    ror
    lsr $00
    ror
rotate_map_graphics_byte_by_wave_phase_c1b70c:
    rts
rotate_map_graphics_byte_by_wave_phase_c1b70d:
    beq rotate_map_graphics_byte_by_wave_phase_c1b70c
    .i8
    cpx #$09
    bne rotate_map_graphics_byte_by_wave_phase_c1b717
rotate_map_graphics_byte_by_wave_phase_c1b713:
    .a8
    cmp #$80
    rol
    rts
rotate_map_graphics_byte_by_wave_phase_c1b717:
    .i8
    cpx #$0F
    beq rotate_map_graphics_byte_by_wave_phase_c1b713
    .i8
    cpx #$0C
    bne rotate_map_graphics_byte_by_wave_phase_c1b722
    .a8
    cmp #$80
    rol
rotate_map_graphics_byte_by_wave_phase_c1b722:
    .a8
    cmp #$80
    rol
    .a8
    cmp #$80
    rol
    rts
