.setcpu "65816"
.segment "CODE"
.org $8B36
map_control_0d8b36:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
