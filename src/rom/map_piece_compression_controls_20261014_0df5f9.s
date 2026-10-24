.setcpu "65816"
.segment "CODE"
.org $F5F9
map_control_0df5f9:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
