; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-motion.md.
.setcpu "65816"
.smart
.a8
.i16

derive_cosine_by_adding_quarter_turn = $2A59
derive_fine_direction_from_coordinate_pairs = $2E77
mask_angle_and_derive_native_sine = $2A60

.segment "CODE"
.org $5B86
aim_linked_child_attack_from_signed_fractional_tip:
    lda a:$00A9,X
    asl
    xba
    clc
    .a16
    adc #$E000
    tay
    lda a:$0002,Y
    sta $46
    lda a:$0004,Y
    sta $4E
    lda a:$00B8,X
    php
    xba
    .a16
    and #$00FF
    plp
    bpl aim_linked_child_attack_from_signed_fractional_tip_c25ba8
    .a16
    ora #$FF00
aim_linked_child_attack_from_signed_fractional_tip_c25ba8:
    clc
    adc a:$002B,X
    sta $56
    lda a:$00BA,X
    php
    xba
    .a16
    and #$00FF
    plp
    bpl aim_linked_child_attack_from_signed_fractional_tip_c25bbc
    .a16
    ora #$FF00
aim_linked_child_attack_from_signed_fractional_tip_c25bbc:
    clc
    adc a:$0032,X
    sta $5E
    jsr derive_fine_direction_from_coordinate_pairs
    asl
    asl
    sta $02
    jsr derive_cosine_by_adding_quarter_turn
    pha
    ldx $87
    asl
    asl
    asl
    sta a:$0076,X
    pla
    .a16
    eor #$FFFF
    inc
    asl
    asl
    sta a:$00BC,X
    lda $02
    jsr mask_angle_and_derive_native_sine
    ldx $87
    pha
    asl
    asl
    asl
    sta a:$0078,X
    pla
    .a16
    eor #$FFFF
    inc
    asl
    asl
    sta a:$00BE,X
    .a16
    lda #$5C0B
    sta a:$0090,X
    .a16
    lda #$5C06
    sta a:$008E,X
    stz a:$0096,X
