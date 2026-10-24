; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


object_evasion = $E1A4
object_defence = $E1A5
object_primary_buffs = $E1B0
object_secondary_conditions = $E191

.segment "CODE"
.org $4FED
calculate_physical_defence_terms:
    lda a:object_evasion,X
    sta $8E
    lsr
    lsr
    sta $A6
    lda a:object_primary_buffs,X
    .a8
    bit #$04
    beq calculate_physical_defence_terms_c05006
    lda $8E
    clc
    adc $A6
    sta $8E
    bra calculate_physical_defence_terms_c05011
calculate_physical_defence_terms_c05006:
    .a8
    bit #$08
    beq calculate_physical_defence_terms_c05011
    lda $8E
    sec
    sbc $A6
    sta $8E
calculate_physical_defence_terms_c05011:
    .a8
    lda #$63
    cmp $8E
    bcs calculate_physical_defence_terms_c05019
    sta $8E
calculate_physical_defence_terms_c05019:
    rep #$20
    lda a:object_defence,X
    sta $87
    lsr
    lsr
    sta $AE
    lda a:object_primary_buffs,X
    .a16
    bit #$0001
    beq calculate_physical_defence_terms_c05035
    lda $87
    clc
    adc $AE
    sta $87
    bra calculate_physical_defence_terms_c05041
calculate_physical_defence_terms_c05035:
    .a16
    bit #$0002
    beq calculate_physical_defence_terms_c05041
    lda $87
    sec
    sbc $AE
    sta $87
calculate_physical_defence_terms_c05041:
    lda a:object_secondary_conditions,X
    .a16
    bit #$0002
    beq calculate_physical_defence_terms_c0504f
    lda $87
    lsr
    lsr
    sta $87
calculate_physical_defence_terms_c0504f:
    .a16
    lda #$03E7
    cmp $87
    bcs calculate_physical_defence_terms_c05058
    sta $87
calculate_physical_defence_terms_c05058:
    sep #$20
    rts
