.setcpu "65816"
.segment "CODE"
.org $633C
map_control_0c633c:
    .byte $E8 ; backreference distance high bits
    .byte $3E ; distance low bit/count
