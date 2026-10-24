.setcpu "65816"
.segment "CODE"
.org $E8A1
map_control_0de8a1:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
