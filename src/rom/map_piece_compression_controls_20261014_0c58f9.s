.setcpu "65816"
.segment "CODE"
.org $58F9
map_control_0c58f9:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
