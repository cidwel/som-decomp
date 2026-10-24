.setcpu "65816"
.segment "CODE"
.org $092C
map_control_0d092c:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
