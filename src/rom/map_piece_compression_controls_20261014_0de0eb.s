.setcpu "65816"
.segment "CODE"
.org $E0EB
map_control_0de0eb:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
