; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

clear_sixteen_floating_number_tile_words = $852B
split_floating_combat_number_into_decimal_fields = $84C9

.segment "CODE"
.org $8425
build_floating_combat_number_tile_records:
    jsr split_floating_combat_number_into_decimal_fields
    jsr clear_sixteen_floating_number_tile_words
    rep #$30
    txa
    asl
    asl
    asl
    clc
    .a16
    adc #$2800
    sta $08
    lda $1E
    .a16
    cmp #$0032
    bcs build_floating_combat_number_tile_records_c18440
    bra build_floating_combat_number_tile_records_c18493
build_floating_combat_number_tile_records_c18440:
    .a16
    cmp #$00C8
    bcs build_floating_combat_number_tile_records_c1844d
    lda $08
    clc
    .a16
    adc #$0280
    sta $08
build_floating_combat_number_tile_records_c1844d:
    lda $04
    bmi build_floating_combat_number_tile_records_c18464
    asl
    asl
    asl
    asl
    asl
    asl
    clc
    adc $08
    sta a:$0000,Y
    clc
    .a16
    adc #$0020
    sta a:$0004,Y
build_floating_combat_number_tile_records_c18464:
    lda $02
    bmi build_floating_combat_number_tile_records_c1847b
    asl
    asl
    asl
    asl
    asl
    asl
    clc
    adc $08
    sta a:$0008,Y
    clc
    .a16
    adc #$0020
    sta a:$000C,Y
build_floating_combat_number_tile_records_c1847b:
    lda $00
    bmi build_floating_combat_number_tile_records_c18492
    asl
    asl
    asl
    asl
    asl
    asl
    clc
    adc $08
    sta a:$0010,Y
    clc
    .a16
    adc #$0020
    sta a:$0014,Y
build_floating_combat_number_tile_records_c18492:
    rts
build_floating_combat_number_tile_records_c18493:
    lda $08
    clc
    .a16
    adc #$0500
    sta $08
    lda $04
    bmi build_floating_combat_number_tile_records_c184aa
    asl
    asl
    asl
    asl
    asl
    clc
    adc $08
    sta a:$0000,Y
build_floating_combat_number_tile_records_c184aa:
    lda $02
    bmi build_floating_combat_number_tile_records_c184b9
    asl
    asl
    asl
    asl
    asl
    clc
    adc $08
    sta a:$0008,Y
build_floating_combat_number_tile_records_c184b9:
    lda $00
    bmi build_floating_combat_number_tile_records_c184c8
    asl
    asl
    asl
    asl
    asl
    clc
    adc $08
    sta a:$0010,Y
build_floating_combat_number_tile_records_c184c8:
    rts
