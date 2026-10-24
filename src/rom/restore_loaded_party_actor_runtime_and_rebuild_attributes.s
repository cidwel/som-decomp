; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-apply.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_actor_appearance_context = $4518
rebuild_actor_attributes_native = $C04530

.segment "CODE"
.org $4C28
restore_loaded_party_actor_runtime_and_rebuild_attributes:
    phd
    phb
    php
    jsr prepare_actor_appearance_context
    rep #$20
    .i16
    ldx #$0000
    stx $B4
    .a16
    lda #$0003
    sta $B2
restore_loaded_party_actor_runtime_and_rebuild_attributes_c04c3a:
    .a16
    lda #$0000
    sta a:$E1F1,X
    sta a:$E1F3,X
    sta a:$E1F5,X
    sta a:$CC78,X
    sep #$20
    sta a:$E1E5,X
    sta a:$E19D,X
    sta a:$E175,X
    .a8
    lda #$FF
    sta a:$E1E5,X
    sta a:$E1F0,X
    rep #$20
    inc $B5
    inc $B5
    ldx $B4
    dec $B2
    bne restore_loaded_party_actor_runtime_and_rebuild_attributes_c04c3a
    sep #$20
    lda a:$00EE
    sta a:$CC6D
    lda a:$00EF
    sta a:$CC6E
    lda a:$00F0
    sta a:$CC6F
    .i16
    ldx #$0000
    jsl f:rebuild_actor_attributes_native
    .i16
    ldx #$0200
    jsl f:rebuild_actor_attributes_native
    .i16
    ldx #$0400
    jsl f:rebuild_actor_attributes_native
    .i16
    ldx #$0000
    stx $B4
    .i16
    ldy #$0003
restore_loaded_party_actor_runtime_and_rebuild_attributes_c04c99:
    lda a:$E191,X
    bpl restore_loaded_party_actor_runtime_and_rebuild_attributes_c04cab
    .a8
    lda #$2F
    sta a:$E1E5,X
    lda a:$E1B1,X
    .a8
    ora #$08
    sta a:$E1B1,X
restore_loaded_party_actor_runtime_and_rebuild_attributes_c04cab:
    inc $B5
    inc $B5
    ldx $B4
    dey
    bne restore_loaded_party_actor_runtime_and_rebuild_attributes_c04c99
    plp
    plb
    pld
    rtl
