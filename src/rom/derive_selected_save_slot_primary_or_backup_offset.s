; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-descriptions.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5D00
derive_selected_save_slot_primary_or_backup_offset:
    lda a:$A162
    .a16
    and #$00FF
    xba
    asl
    asl
    tax
    lda a:$A216
    lsr
    bcc derive_selected_save_slot_primary_or_backup_offset_c75d16
    txa
    clc
    .a16
    adc #$1000
    tax
derive_selected_save_slot_primary_or_backup_offset_c75d16:
    rts
