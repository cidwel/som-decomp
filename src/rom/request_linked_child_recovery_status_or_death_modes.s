; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-parent-update.md.
.setcpu "65816"
.smart
.a8
.i16

consume_boss_byte34_bit0_or_return_negative_status = $0501
derive_boss_threshold_from_hardware_division_and_clamp = $5920

.segment "CODE"
.org $5951
request_linked_child_recovery_status_or_death_modes:
    ldx $87
    lda a:$00BE,X
    beq request_linked_child_recovery_status_or_death_modes_c259a6
    cmp a:$0182,X
    bcc request_linked_child_recovery_status_or_death_modes_c259a6
    jsr derive_boss_threshold_from_hardware_division_and_clamp
    lda a:$00BA,X
    sta a:$00BC,X
    ldx $87
    lda a:$00A9,X
    asl
    xba
    tay
    lda a:$0002,Y
    cmp a:$002B,X
    bcc request_linked_child_recovery_status_or_death_modes_c25986
    ldy a:$00B0,X
    lda a:$0083,Y
    bmi request_linked_child_recovery_status_or_death_modes_c25986
    .a16
    lda #$0006
    sta a:$0081,Y
    bra request_linked_child_recovery_status_or_death_modes_c259bc
request_linked_child_recovery_status_or_death_modes_c25986:
    ldy a:$00B2,X
    lda a:$0083,Y
    bmi request_linked_child_recovery_status_or_death_modes_c25996
    .a16
    lda #$0006
    sta a:$0081,Y
    bra request_linked_child_recovery_status_or_death_modes_c259bc
request_linked_child_recovery_status_or_death_modes_c25996:
    ldy a:$00B0,X
    lda a:$0083,Y
    bmi request_linked_child_recovery_status_or_death_modes_c259a6
    .a16
    lda #$0006
    sta a:$0081,Y
    bra request_linked_child_recovery_status_or_death_modes_c259bc
request_linked_child_recovery_status_or_death_modes_c259a6:
    jsr consume_boss_byte34_bit0_or_return_negative_status
    bcc request_linked_child_recovery_status_or_death_modes_c259bc
    ldx $87
    ldy a:$00B0,X
    .a16
    lda #$0002
    sta a:$0081,Y
    ldy a:$00B2,X
    sta a:$0081,Y
request_linked_child_recovery_status_or_death_modes_c259bc:
    ldx $87
    lda a:$0190,X
    bmi request_linked_child_recovery_status_or_death_modes_c259c4
    rts
request_linked_child_recovery_status_or_death_modes_c259c4:
    ldy a:$00B0,X
    .a16
    lda #$0004
    sta a:$0081,Y
    ldy a:$00B2,X
    sta a:$0081,Y
    .a16
    lda #$59DD
    sta a:$008E,X
    stz a:$0094,X
    rts
