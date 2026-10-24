; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $12E2
merge_boss_contact_direction_flags:
    stz $4A
    lda $46
    sec
    sbc $56
    bpl merge_boss_contact_direction_flags_c212ef
    .a16
    eor #$FFFF
    inc
merge_boss_contact_direction_flags_c212ef:
    sta $52
    lda $48
    clc
    adc $58
    cmp $52
    bcc merge_boss_contact_direction_flags_c21330
    lda $4E
    sec
    sbc $5E
    bpl merge_boss_contact_direction_flags_c21305
    .a16
    eor #$FFFF
    inc
merge_boss_contact_direction_flags_c21305:
    sta $52
    lda $50
    clc
    adc $60
    cmp $52
    bcc merge_boss_contact_direction_flags_c21330
    lda $46
    sec
    sbc $56
    eor $59
    bmi merge_boss_contact_direction_flags_c21320
    .a16
    lda #$0001
    ora $4A
    sta $4A
merge_boss_contact_direction_flags_c21320:
    lda $4E
    sec
    sbc $5E
    eor $5A
    bmi merge_boss_contact_direction_flags_c21330
    .a16
    lda #$0002
    ora $4A
    sta $4A
merge_boss_contact_direction_flags_c21330:
    sep #$20
    ldx $95
    lda $4A
    ora a:$0029,X
    sta a:$0029,X
    rep #$20
    rts
