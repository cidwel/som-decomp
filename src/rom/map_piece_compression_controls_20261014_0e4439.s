.setcpu "65816"
.segment "CODE"
.org $4439
map_control_0e4439:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
