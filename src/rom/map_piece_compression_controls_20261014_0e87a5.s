.setcpu "65816"
.segment "CODE"
.org $87A5
map_control_0e87a5:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
