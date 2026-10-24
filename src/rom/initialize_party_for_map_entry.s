; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

assign_party_palette_rows = $DF96
find_actor_controller_binding = $DF0A
initialize_party_tile_state = $DF26
prepare_and_place_party_actor = $E06F
prepare_party_entry_walk = $DD66
routine_02aef4 = $2AEF4
start_uncontrolled_party_programs = $DE00

.segment "CODE"
.org $DC8F
initialize_party_for_map_entry:
    jsl f:routine_02aef4
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$30
    .a16
    lda #$CB00
    .i16
    ldx #$03FE
initialize_party_for_map_entry_c1dca2:
    sta a:$0C00,X
    dex
    dex
    bpl initialize_party_for_map_entry_c1dca2
    .i16
    ldx #$01FE
initialize_party_for_map_entry_c1dcac:
    stz a:$D000,X
    dex
    dex
    bpl initialize_party_for_map_entry_c1dcac
    rep #$20
    .a16
    lda #$0C00
    sta a:$E06E
    .a16
    lda #$0C20
    sta a:$E26E
    .a16
    lda #$0C40
    sta a:$E46E
    .a16
    lda #$0C60
    sta a:$E06C
    .a16
    lda #$0CB0
    sta a:$E26C
    .a16
    lda #$0D00
    sta a:$E46C
    .a16
    lda #$23C0
    eor $98
    sta a:$E08A
    .a16
    lda #$25C8
    eor $98
    sta a:$E28A
    .a16
    lda #$27E0
    eor $98
    sta a:$E48A
    .a16
    lda #$0144
    eor $98
    sta a:$E086
    .a16
    lda #$0168
    eor $98
    sta a:$E286
    .a16
    lda #$018C
    eor $98
    sta a:$E486
    jsr assign_party_palette_rows
    .i16
    ldx #$0000
    jsr prepare_and_place_party_actor
    .i16
    ldx #$0200
    jsr prepare_and_place_party_actor
    .i16
    ldx #$0400
    jsr prepare_and_place_party_actor
    sep #$20
    .a8
    lda #$08
    sta a:$E01E
    .a8
    lda #$04
    sta a:$E21E
    .a8
    lda #$00
    sta a:$E41E
    .a8
    lda #$01
    jsr find_actor_controller_binding
    sta a:$E02C
    .a8
    lda #$02
    jsr find_actor_controller_binding
    sta a:$E22C
    .a8
    lda #$04
    jsr find_actor_controller_binding
    sta a:$E42C
    jsr initialize_party_tile_state
    jsr prepare_party_entry_walk
    jsr start_uncontrolled_party_programs
    rep #$20
    lda a:$010E
    bne initialize_party_for_map_entry_c1dd64
    sep #$20
    .a8
    lda #$80
    sta a:$E00E
    sta a:$E20E
    sta a:$E40E
initialize_party_for_map_entry_c1dd64:
    plb
    rtl
