.setcpu "65816"
.segment "CODE"
.org $BA12
map_control_0eba12:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
