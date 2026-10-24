.setcpu "65816"
.segment "CODE"
.org $C0C5
map_control_0ec0c5:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
