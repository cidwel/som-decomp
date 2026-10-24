; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

call_actor_status_program_long = $C10024
clear_map_menu_workspace_jump = $C00098

.segment "CODE"
.org $5D46
clear_map_entry_party_effects:
    phd
    phb
    php
    rep #$30
    .a16
    lda #$0300
    tcd
    sep #$20
    .a8
    lda #$7E
    pha
    plb
    rep #$20
    .i16
    ldx #$FE00
    .a16
    lda #$0000
    .i16
    ldy #$0100
clear_map_entry_party_effects_c05d60:
    sta a:$0000,X
    inx
    inx
    dey
    bne clear_map_entry_party_effects_c05d60
    .a16
    lda #$0400
    sta $B4
clear_map_entry_party_effects_c05d6d:
    ldx $B4
    rep #$20
    stz a:$E1F1,X
    stz a:$E1F3,X
    stz a:$E1F5,X
    lda a:$E190,X
    .a16
    and #$F7EC
    sta a:$E190,X
    sep #$20
    stz a:$E059,X
    lda a:$E02C,X
    beq clear_map_entry_party_effects_c05d9b
    rep #$20
    lda a:$E190,X
    .a16
    bit #$4160
    sep #$20
    bne clear_map_entry_party_effects_c05d9b
    bra clear_map_entry_party_effects_c05da1
clear_map_entry_party_effects_c05d9b:
    .a8
    lda #$01
    jsl f:call_actor_status_program_long
clear_map_entry_party_effects_c05da1:
    dec $B5
    dec $B5
    bpl clear_map_entry_party_effects_c05d6d
    .a8
    lda #$00
    sta $A0
    sta $9F
    sta $A2
    sta $A1
    sta $A3
    jsl f:clear_map_menu_workspace_jump
    plp
    plb
    pld
    rtl
