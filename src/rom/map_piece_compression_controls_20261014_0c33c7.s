.setcpu "65816"
.segment "CODE"
.org $33C7
map_control_0c33c7:
    .byte $E8 ; backreference distance high bits
    .byte $21 ; distance low bit/count
