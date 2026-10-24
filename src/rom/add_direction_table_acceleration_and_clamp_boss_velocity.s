; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $32BC
add_direction_table_acceleration_and_clamp_boss_velocity:
    lda $1A
    .a16
    eor #$FFFF
    inc
    sta $1C
    lda a:$00AB,X
    asl
    asl
    tay
    lda [$0C],Y
    sta $95
    iny
    iny
    lda [$0C],Y
    sta $97
    lda $95
    clc
    adc a:$003C,X
    sta a:$003C,X
    bmi add_direction_table_acceleration_and_clamp_boss_velocity_c232ea
    cmp $1A
    bcc add_direction_table_acceleration_and_clamp_boss_velocity_c232f3
    lda $1A
    sta a:$003C,X
    bra add_direction_table_acceleration_and_clamp_boss_velocity_c232f3
add_direction_table_acceleration_and_clamp_boss_velocity_c232ea:
    cmp $1C
    bcs add_direction_table_acceleration_and_clamp_boss_velocity_c232f3
    lda $1C
    sta a:$003C,X
add_direction_table_acceleration_and_clamp_boss_velocity_c232f3:
    lda $97
    clc
    adc a:$0040,X
    sta a:$0040,X
    bmi add_direction_table_acceleration_and_clamp_boss_velocity_c23309
    cmp $1A
    bcc add_direction_table_acceleration_and_clamp_boss_velocity_c23312
    lda $1A
    sta a:$0040,X
    bra add_direction_table_acceleration_and_clamp_boss_velocity_c23312
add_direction_table_acceleration_and_clamp_boss_velocity_c23309:
    cmp $1C
    bcs add_direction_table_acceleration_and_clamp_boss_velocity_c23312
    lda $1C
    sta a:$0040,X
add_direction_table_acceleration_and_clamp_boss_velocity_c23312:
    rts
