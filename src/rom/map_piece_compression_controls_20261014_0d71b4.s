.setcpu "65816"
.segment "CODE"
.org $71B4
map_control_0d71b4:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
