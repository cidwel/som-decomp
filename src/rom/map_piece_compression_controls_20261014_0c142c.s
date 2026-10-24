.setcpu "65816"
.segment "CODE"
.org $142C
map_control_0c142c:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
