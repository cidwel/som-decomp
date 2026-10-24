; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-thirteen-trajectory.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $69F7
terminate_descriptor_thirteen_trajectory_at_height_floor:
    lda a:$0066,X
    bmi terminate_descriptor_thirteen_trajectory_at_height_floor_c26a01
    .a16
    cmp #$0081
    bcs terminate_descriptor_thirteen_trajectory_at_height_floor_c26a0f
terminate_descriptor_thirteen_trajectory_at_height_floor_c26a01:
    stz a:$0090,X
    stz a:$0064,X
    .a16
    lda #$0080
    sta a:$0066,X
    sec
    rts
terminate_descriptor_thirteen_trajectory_at_height_floor_c26a0f:
    clc
    rts
