; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-descriptions.md.
.setcpu "65816"
.smart
.a8
.i16

derive_selected_save_slot_primary_or_backup_offset = $5D00

.segment "CODE"
.org $5A32
append_native_saved_slot_location_name:
    lda a:$A216
    .a8
    and #$03
    .a8
    cmp #$03
    beq append_native_saved_slot_location_name_c75a86
    phx
    rep #$20
    jsr derive_selected_save_slot_primary_or_backup_offset
    sep #$20
    .a8
    lda #$00
    xba
    lda f:$306101,X
    .a8
    and #$0F
    asl
    asl
    asl
    asl
    sta a:$A173
    lda f:$306102,X
    .a8
    and #$F0
    lsr
    lsr
    lsr
    lsr
    clc
    adc a:$A173
    asl
    tay
    plx
    phb
    .a8
    lda #$CA
    pha
    plb
    rep #$20
    lda a:$0B82,Y
    tay
    sep #$20
    .a8
    lda #$80
    sta f:$7E9C00,X
    inx
append_native_saved_slot_location_name_c75a78:
    lda a:$0000,Y
    beq append_native_saved_slot_location_name_c75a85
    sta f:$7E9C00,X
    inx
    iny
    bra append_native_saved_slot_location_name_c75a78
append_native_saved_slot_location_name_c75a85:
    plb
append_native_saved_slot_location_name_c75a86:
    rts
