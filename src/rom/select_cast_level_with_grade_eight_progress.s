; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

random_byte_long_wrapper = $C0389C

.segment "CODE"
.org $4EAC
select_cast_level_with_grade_eight_progress:
    lda a:$E1FB,X
    .a8
    bit #$C0
    bne select_cast_level_with_grade_eight_progress_d04eb9
select_cast_level_with_grade_eight_progress_d04eb3:
    lda $9D
    sta a:$E171,X
    rts
select_cast_level_with_grade_eight_progress_d04eb9:
    lda $9D
    .a8
    cmp #$08
    bne select_cast_level_with_grade_eight_progress_d04ecc
    jsl f:random_byte_long_wrapper
    lsr
    inc
    cmp $9E
    bcc select_cast_level_with_grade_eight_progress_d04eb3
    lda $9D
    dec
select_cast_level_with_grade_eight_progress_d04ecc:
    sta a:$E171,X
    rts
