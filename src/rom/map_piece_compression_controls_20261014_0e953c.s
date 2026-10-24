.setcpu "65816"
.segment "CODE"
.org $953C
map_control_0e953c:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
