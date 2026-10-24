.setcpu "65816"
.segment "CODE"
.org $9904
map_control_0d9904:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
