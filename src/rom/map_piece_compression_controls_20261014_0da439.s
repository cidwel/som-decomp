.setcpu "65816"
.segment "CODE"
.org $A439
map_control_0da439:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
