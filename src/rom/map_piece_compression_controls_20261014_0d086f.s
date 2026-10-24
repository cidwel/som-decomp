.setcpu "65816"
.segment "CODE"
.org $086F
map_control_0d086f:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
