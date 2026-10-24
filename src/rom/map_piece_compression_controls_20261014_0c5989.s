.setcpu "65816"
.segment "CODE"
.org $5989
map_control_0c5989:
    .byte $E9 ; backreference distance high bits
    .byte $89 ; distance low bit/count
