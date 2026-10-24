.setcpu "65816"
.segment "CODE"
.org $BA0C
map_control_0fba0c:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
