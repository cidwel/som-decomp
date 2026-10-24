.setcpu "65816"
.segment "CODE"
.org $664C
map_control_0d664c:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
