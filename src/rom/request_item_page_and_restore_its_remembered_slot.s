; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-navigation.md.
.setcpu "65816"
.smart
.a8
.i16

preserve_accumulator_byte_and_request_fixed_local_audio_presets = $1BA5

.segment "CODE"
.org $2D50
request_item_page_and_restore_its_remembered_slot:
    .a8
    lda #$09
    sta a:$A210
    lda a:$A211
    sta a:$A17B
    lda a:$A17A
    sta a:$A211
    jsr preserve_accumulator_byte_and_request_fixed_local_audio_presets
    .a8
    lda #$40
    trb a:$A20A
    .a8
    lda #$01
    tsb a:$A20A
    rts
