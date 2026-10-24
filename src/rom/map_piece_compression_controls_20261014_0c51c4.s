.setcpu "65816"
.segment "CODE"
.org $51C4
map_control_0c51c4:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
