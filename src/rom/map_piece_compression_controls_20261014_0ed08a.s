.setcpu "65816"
.segment "CODE"
.org $D08A
map_control_0ed08a:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
