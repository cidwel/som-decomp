; Recovered Secret of Mana USA routine; behaviour documented in docs/map-object-direction-window.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c0e111 = $E111

.segment "CODE"
.org $E058
select_directional_map_object_load_window:
    rep #$30
    ldy $BA
    lda a:$E006,Y
    sep #$20
    xba
    bne select_directional_map_object_load_window_c0e06b
    xba
    beq select_directional_map_object_load_window_c0e07b
    bpl select_directional_map_object_load_window_c0e0d3
    bmi select_directional_map_object_load_window_c0e0df
select_directional_map_object_load_window_c0e06b:
    bpl select_directional_map_object_load_window_c0e074
    xba
    beq select_directional_map_object_load_window_c0e0bb
    bmi select_directional_map_object_load_window_c0e0af
    bpl select_directional_map_object_load_window_c0e0a3
select_directional_map_object_load_window_c0e074:
    xba
    beq select_directional_map_object_load_window_c0e0c7
    bmi select_directional_map_object_load_window_c0e097
    bpl select_directional_map_object_load_window_c0e08b
select_directional_map_object_load_window_c0e07b:
    lda $F4
    lsr
    lsr
    .a8
    and #$03
    beq select_directional_map_object_load_window_c0e0df
    dec
    beq select_directional_map_object_load_window_c0e0d3
    dec
    beq select_directional_map_object_load_window_c0e0bb
    bra select_directional_map_object_load_window_c0e0c7
select_directional_map_object_load_window_c0e08b:
    rep #$20
    .a16
    lda #$0612
    sta $00
    .a16
    lda #$1008
    bra routine_c0e111
select_directional_map_object_load_window_c0e097:
    rep #$20
    .a16
    lda #$06F8
    sta $00
    .a16
    lda #$1008
    bra routine_c0e111
select_directional_map_object_load_window_c0e0a3:
    rep #$20
    .a16
    lda #$0612
    sta $00
    .a16
    lda #$10F8
    bra routine_c0e111
select_directional_map_object_load_window_c0e0af:
    rep #$20
    .a16
    lda #$06F8
    sta $00
    .a16
    lda #$10F8
    bra routine_c0e111
select_directional_map_object_load_window_c0e0bb:
    rep #$20
    .a16
    lda #$14FE
    sta $00
    .a16
    lda #$06F8
    bra routine_c0e111
select_directional_map_object_load_window_c0e0c7:
    rep #$20
    .a16
    lda #$14FE
    sta $00
    .a16
    lda #$0612
    bra routine_c0e111
select_directional_map_object_load_window_c0e0d3:
    rep #$20
    .a16
    lda #$0612
    sta $00
    .a16
    lda #$12FE
    bra routine_c0e111
select_directional_map_object_load_window_c0e0df:
    rep #$20
    .a16
    lda #$06F8
    sta $00
    .a16
    lda #$12FE
    bra routine_c0e111
