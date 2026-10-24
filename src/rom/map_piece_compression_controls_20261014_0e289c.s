.setcpu "65816"
.segment "CODE"
.org $289C
map_control_0e289c:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
