; Recovered Secret of Mana USA boot routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16


object_element_weakness = $E1A1
object_element_resistance = $E1A3

.segment "CODE"
.org $E8A0
select_spell_element_multiplier:
    .i16
    ldy #$2ADC
    lda [$DC],Y
    ldy $83
    bit a:object_element_resistance,X
    beq select_spell_element_multiplier_c8e8b1
    .a8
    lda #$01
    sta $8F
    rts
select_spell_element_multiplier_c8e8b1:
    bit a:object_element_weakness,X
    beq select_spell_element_multiplier_c8e8bb
    .a8
    lda #$04
    sta $8F
    rts
select_spell_element_multiplier_c8e8bb:
    .a8
    lda #$02
    sta $8F
    rts
