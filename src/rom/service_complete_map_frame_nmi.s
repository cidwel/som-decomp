; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

restore_map_saved_palette_rows = $C42C
upload_complete_actor_frame_tiles_mirror = $1950D
upload_map_frame_hud_and_animated_characters = $C238
upload_map_menu_and_prepare_palette_hdma = $C1E7
upload_pending_map_tile_rows_and_columns = $C692
write_map_frame_background_scroll = $C170

.segment "CODE"
.org $C0A8
service_complete_map_frame_nmi:
    rep #$30
    pha
    phx
    phy
    phd
    phb
    .a16
    lda #$0000
    tcd
    sep #$20
    pha
    plb
    lda a:$4210
    .a8
    lda #$8F
    sta a:$2100
    stz a:$420C
    lda $29
    .a8
    bit #$04
    beq service_complete_map_frame_nmi_c0c0d0
    sta a:$2105
    lda $21
    sta a:$212C
service_complete_map_frame_nmi_c0c0d0:
    lda a:$1D04
    .a8
    bit #$20
    bne service_complete_map_frame_nmi_c0c0f0
    lda a:$010E
    ora a:$010F
    beq service_complete_map_frame_nmi_c0c0ea
    .a8
    lda #$03
    trb $2C
    beq service_complete_map_frame_nmi_c0c0ea
    jsr restore_map_saved_palette_rows
    bra service_complete_map_frame_nmi_c0c0f0
service_complete_map_frame_nmi_c0c0ea:
    lda $EC
    .a8
    bit #$05
    beq service_complete_map_frame_nmi_c0c118
service_complete_map_frame_nmi_c0c0f0:
    .a8
    lda #$00
    sta a:$2121
    .i16
    ldx #$0600
    lda $2A
    beq service_complete_map_frame_nmi_c0c0ff
    .i16
    ldx #$BE00
service_complete_map_frame_nmi_c0c0ff:
    stx a:$4372
    .i16
    ldx #$2200
    stx a:$4370
    .a8
    lda #$7E
    sta a:$4374
    .i16
    ldx #$0200
    stx a:$4375
    .a8
    lda #$80
    sta a:$420B
service_complete_map_frame_nmi_c0c118:
    .a8
    lda #$09
    bit $EC
    beq service_complete_map_frame_nmi_c0c13e
    .i16
    ldx #$0000
    stx a:$2102
    .i16
    ldx #$0800
    stx a:$4372
    .i16
    ldx #$0400
    stx a:$4370
    stz a:$4374
    .i16
    ldx #$0220
    stx a:$4375
    .a8
    lda #$80
    sta a:$420B
service_complete_map_frame_nmi_c0c13e:
    .a8
    lda #$01
    bit $EC
    beq service_complete_map_frame_nmi_c0c155
    rep #$20
    inc $F4
    jsr upload_pending_map_tile_rows_and_columns
    jsr upload_map_frame_hud_and_animated_characters
    jsl f:upload_complete_actor_frame_tiles_mirror
    jsr write_map_frame_background_scroll
service_complete_map_frame_nmi_c0c155:
    jsr upload_map_menu_and_prepare_palette_hdma
    sep #$20
    lda $2C
    sta a:$420C
    lda $E6
    sta a:$2100
    .a8
    lda #$FF
    trb $EC
    rep #$30
    plb
    pld
    ply
    plx
    pla
    rti
