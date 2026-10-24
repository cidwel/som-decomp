.setcpu "65816"
.segment "CODE"
.org $37A1
map_control_0f37a1:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
