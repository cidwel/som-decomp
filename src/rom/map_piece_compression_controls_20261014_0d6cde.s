.setcpu "65816"
.segment "CODE"
.org $6CDE
map_control_0d6cde:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
