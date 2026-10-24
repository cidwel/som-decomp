.setcpu "65816"
.segment "CODE"
.org $C795
map_control_0ec795:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
