.setcpu "65816"
.segment "CODE"
.org $15FA
map_control_0c15fa:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
