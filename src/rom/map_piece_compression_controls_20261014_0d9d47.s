.setcpu "65816"
.segment "CODE"
.org $9D47
map_control_0d9d47:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
