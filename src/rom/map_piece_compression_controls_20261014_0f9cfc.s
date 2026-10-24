.setcpu "65816"
.segment "CODE"
.org $9CFC
map_control_0f9cfc:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
