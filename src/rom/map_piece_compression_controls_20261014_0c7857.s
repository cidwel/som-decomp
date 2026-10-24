.setcpu "65816"
.segment "CODE"
.org $7857
map_control_0c7857:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
