.setcpu "65816"
.segment "CODE"
.org $29EB
map_control_0e29eb:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
