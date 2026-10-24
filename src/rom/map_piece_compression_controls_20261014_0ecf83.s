.setcpu "65816"
.segment "CODE"
.org $CF83
map_control_0ecf83:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
