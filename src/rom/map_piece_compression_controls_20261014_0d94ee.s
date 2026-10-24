.setcpu "65816"
.segment "CODE"
.org $94EE
map_control_0d94ee:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
