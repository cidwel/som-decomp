.setcpu "65816"
.segment "CODE"
.org $9229
map_control_0c9229:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
