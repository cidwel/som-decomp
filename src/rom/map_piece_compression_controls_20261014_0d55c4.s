.setcpu "65816"
.segment "CODE"
.org $55C4
map_control_0d55c4:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
