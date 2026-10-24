.setcpu "65816"
.segment "CODE"
.org $E8EB
map_control_0de8eb:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
