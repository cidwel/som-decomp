; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-child.md.
.setcpu "65816"
.smart
.a8
.i16

consume_linked_child_request_and_select_native_definition = $5E9D
request_boss_sound_with_parameter_word = $30E3

.segment "CODE"
.org $5A66
advance_linked_child_strip_collapse_and_request_sound:
    .a16
    lda #$1AA4
    clc
    adc a:$0049,X
    sta $00
    lda $89
    clc
    .a16
    adc #$0014
    tax
    .i16
    ldy #$0006
advance_linked_child_strip_collapse_and_request_sound_c25a79:
    lda $00
    .a16
    and #$01FF
    .a16
    cmp #$00AA
    bcc advance_linked_child_strip_collapse_and_request_sound_c25a88
    .a16
    lda #$1AAA
    bra advance_linked_child_strip_collapse_and_request_sound_c25a8a
advance_linked_child_strip_collapse_and_request_sound_c25a88:
    lda $00
advance_linked_child_strip_collapse_and_request_sound_c25a8a:
    sta a:$0003,X
    lda $00
    sec
    .a16
    sbc #$0002
    sta $00
    .a16
    and #$01FF
    .a16
    cmp #$00A4
    bcc advance_linked_child_strip_collapse_and_request_sound_c25aac
    dex
    dex
    dex
    dex
    dey
    bne advance_linked_child_strip_collapse_and_request_sound_c25a79
    ldx $87
    .a16
    lda #$5ACF
    sta a:$008E,X
advance_linked_child_strip_collapse_and_request_sound_c25aac:
    ldx $87
    inc a:$0049,X
    inc a:$0049,X
    .a16
    lda #$0015
    .i16
    ldx #$000F
    jsr request_boss_sound_with_parameter_word
    ldx $87
    lda a:$0081,X
    .a16
    cmp #$0004
    bne advance_linked_child_strip_collapse_and_request_sound_c25aca
    jsr consume_linked_child_request_and_select_native_definition
advance_linked_child_strip_collapse_and_request_sound_c25aca:
    stz a:$0081,X
    clc
    rts
