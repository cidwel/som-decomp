; Recovered Secret of Mana USA spell routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

apply_weapon_saber_spell = $EABF



.segment "CODE"
.org $EAA8
ice_saber_entry:
    .a8
    lda #$04
    pha
    bra apply_weapon_saber_spell
