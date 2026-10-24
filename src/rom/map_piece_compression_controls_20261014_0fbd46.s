.setcpu "65816"
.segment "CODE"
.org $BD46
map_control_0fbd46:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
