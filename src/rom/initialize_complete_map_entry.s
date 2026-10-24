; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

clear_map_entry_party_effects_jump = $C00060
initialize_map_header_resources = $C481
initialize_map_sprite_workspace = $E355
install_map_interrupt_jump_template = $BC85
load_map_tile_layers_and_camera = $C9EA
load_ordinary_map_objects = $DCDC
request_map_entry_fade = $8B30
routine_01dc8f = $1DC8F
routine_01e0d7 = $1E0D7
routine_01f29c = $1F29C
routine_01fd4e = $1FD4E
routine_02a6c5 = $2A6C5
routine_02aa5c = $2AA5C
routine_02cec1 = $2CEC1

.segment "CODE"
.org $BC0B
initialize_complete_map_entry:
    jsr install_map_interrupt_jump_template
    jsr initialize_map_header_resources
    jsr load_map_tile_layers_and_camera
    jsl f:routine_02aa5c
    jsl f:routine_01fd4e
    jsl f:routine_02a6c5
    jsl f:routine_01dc8f
    jsr load_ordinary_map_objects
    jsl f:routine_01e0d7
    jsr initialize_map_sprite_workspace
    rep #$10
    .i16
    ldx #$0200
    stx a:$0120
    .i16
    ldx #$0F00
    .i16
    ldy #$0101
    jsr request_map_entry_fade
    jsl f:routine_01f29c
    sep #$20
    stz a:$1D04
    sep #$30
    .a8
    lda #$0F
    trb $E3
    lda $B0
    sta a:$210D
    stz a:$210D
    lda $B2
    sta a:$210E
    stz a:$210E
    lda $E8
    .a8
    and #$03
    sta $52
    .a8
    lda #$B8
    sta a:$4207
    stz a:$4208
    .a8
    lda #$C4
    sta a:$4209
    stz a:$420A
    lda a:$010E
    ora a:$010F
    bne initialize_complete_map_entry_c0bc80
    jsl f:routine_02cec1
initialize_complete_map_entry_c0bc80:
    jsl f:clear_map_entry_party_effects_jump
    rts
