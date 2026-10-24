.setcpu "65816"
.segment "CODE"
.org $9439
map_control_0f9439:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
