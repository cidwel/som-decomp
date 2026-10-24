; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-descriptions.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_saved_slot_format_pair = $59E0
derive_selected_save_slot_primary_or_backup_offset = $5D00

.segment "CODE"
.org $5AAB
append_native_saved_slot_name_or_empty_label:
    .a8
    lda #$05
    jsr append_native_saved_slot_format_pair
    lda a:$A216
    .a8
    and #$03
    .a8
    cmp #$03
    bne append_native_saved_slot_name_or_empty_label_c75ad0
    txy
    .i16
    ldx #$0000
    .a8
    lda #$05
append_native_saved_slot_name_or_empty_label_c75abf:
    xba
    lda f:$C77805,X
    sta a:$9C00,Y
    iny
    inx
    xba
    dec
    bne append_native_saved_slot_name_or_empty_label_c75abf
    tyx
    bra append_native_saved_slot_name_or_empty_label_c75aec
append_native_saved_slot_name_or_empty_label_c75ad0:
    rep #$20
    phx
    jsr derive_selected_save_slot_primary_or_backup_offset
    sep #$20
    ply
    .a8
    lda #$0C
append_native_saved_slot_name_or_empty_label_c75adb:
    xba
    lda f:$306003,X
    beq append_native_saved_slot_name_or_empty_label_c75aeb
    sta a:$9C00,Y
    inx
    iny
    xba
    dec
    bne append_native_saved_slot_name_or_empty_label_c75adb
append_native_saved_slot_name_or_empty_label_c75aeb:
    tyx
append_native_saved_slot_name_or_empty_label_c75aec:
    rts
