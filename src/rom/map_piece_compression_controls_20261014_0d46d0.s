.setcpu "65816"
.segment "CODE"
.org $46D0
map_control_0d46d0:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
