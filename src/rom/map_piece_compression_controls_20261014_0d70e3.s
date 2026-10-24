.setcpu "65816"
.segment "CODE"
.org $70E3
map_control_0d70e3:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
