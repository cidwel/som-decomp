.setcpu "65816"
.segment "CODE"
.org $9CDE
map_control_0f9cde:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
