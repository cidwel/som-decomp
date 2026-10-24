; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5CF1
integrate_linked_child_tip_velocity_with_parent_status_gate:
    ldx $87
    ldy a:$00B0,X
    lda a:$0060,Y
    .a16
    and #$00FF
    .a16
    cmp #$0040
    beq integrate_linked_child_tip_velocity_with_parent_status_gate_c25d07
    .a16
    bit #$00E0
    beq integrate_linked_child_tip_velocity_with_parent_status_gate_c25d07
    rts
integrate_linked_child_tip_velocity_with_parent_status_gate_c25d07:
    ldx $87
    .i16
    ldy #$0002
integrate_linked_child_tip_velocity_with_parent_status_gate_c25d0c:
    lda a:$00BC,X
    clc
    adc a:$00B8,X
    sta $00
    bpl integrate_linked_child_tip_velocity_with_parent_status_gate_c25d1b
    .a16
    eor #$FFFF
    inc
integrate_linked_child_tip_velocity_with_parent_status_gate_c25d1b:
    .a16
    cmp #$5000
    bcs integrate_linked_child_tip_velocity_with_parent_status_gate_c25d25
    lda $00
    sta a:$00B8,X
integrate_linked_child_tip_velocity_with_parent_status_gate_c25d25:
    inx
    inx
    dey
    bne integrate_linked_child_tip_velocity_with_parent_status_gate_c25d0c
    ldx $87
    rts
