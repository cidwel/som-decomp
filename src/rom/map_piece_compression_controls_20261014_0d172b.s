.setcpu "65816"
.segment "CODE"
.org $172B
map_control_0d172b:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
