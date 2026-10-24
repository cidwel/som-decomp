.setcpu "65816"
.segment "CODE"
.org $E7F4
map_control_0fe7f4:
    .byte $E8 ; backreference distance high bits
    .byte $3E ; distance low bit/count
