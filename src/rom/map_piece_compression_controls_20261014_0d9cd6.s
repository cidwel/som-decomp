.setcpu "65816"
.segment "CODE"
.org $9CD6
map_control_0d9cd6:
    .byte $E8 ; backreference distance high bits
    .byte $9E ; distance low bit/count
