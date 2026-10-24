; Recovered Secret of Mana USA spell routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

apply_weapon_saber_spell = $EABF



.segment "CODE"
.org $EAB2
thunder_saber_entry:
    .a8
    lda #$02
    pha
    bra apply_weapon_saber_spell
