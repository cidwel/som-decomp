; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-body.md.
.setcpu "65816"
.smart
.a8
.i16

consume_boss_byte34_bit0_or_return_negative_status = $0501
consume_boss_byte35_request = $051C

.segment "CODE"
.org $4DB9
consume_body_damage_or_parent_phase15_and_enter_hurt:
    jsr consume_boss_byte35_request
    jsr consume_boss_byte34_bit0_or_return_negative_status
    bcs consume_body_damage_or_parent_phase15_and_enter_hurt_c24dcd
    lda a:$00B0,X
    tax
    lda a:$0094,X
    .a16
    cmp #$000F
    bne consume_body_damage_or_parent_phase15_and_enter_hurt_c24dda
consume_body_damage_or_parent_phase15_and_enter_hurt_c24dcd:
    ldx $87
    .a16
    lda #$0007
    sta a:$0094,X
    stz a:$0096,X
    sec
    rts
consume_body_damage_or_parent_phase15_and_enter_hurt_c24dda:
    ldx $87
    clc
    rts
