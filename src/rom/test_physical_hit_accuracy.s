; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


object_primary_buffs = $E1B0
object_primary_conditions = $E190
object_accuracy = $E197
object_weapon_gauge = $E1ED

.segment "CODE"
.org $505B
test_physical_hit_accuracy:
    lda a:object_accuracy,Y
    sta $8D
    lda a:object_primary_conditions,Y
    .a8
    bit #$04
    beq test_physical_hit_accuracy_c05076
    lda $8D
    lsr
    lsr
    lsr
    lsr
    sta $A4
    lda $8D
    sec
    sbc $A4
    sta $8D
test_physical_hit_accuracy_c05076:
    lsr
    lsr
    sta $A6
    lda a:object_primary_buffs,Y
    .a8
    bit #$10
    beq test_physical_hit_accuracy_c0508a
    lda $8D
    clc
    adc $A6
    sta $8D
    bra test_physical_hit_accuracy_c05095
test_physical_hit_accuracy_c0508a:
    .a8
    bit #$20
    beq test_physical_hit_accuracy_c05095
    lda $8D
    sec
    sbc $A6
    sta $8D
test_physical_hit_accuracy_c05095:
    .a8
    lda #$63
    cmp $8D
    bcs test_physical_hit_accuracy_c0509d
    sta $8D
test_physical_hit_accuracy_c0509d:
    lda a:object_weapon_gauge,Y
    beq test_physical_hit_accuracy_c050a7
    lda $8D
    lsr
    sta $8D
test_physical_hit_accuracy_c050a7:
    jsl f:$C0389C
    sta f:$004202
    lda $8E
    lsr
    sta f:$004203
    sta $A4
    nop
    nop
    nop
    nop
    lda f:$004217
    clc
    adc $A4
    sta $A4
    lda $8D
    cmp $A4
    rts
