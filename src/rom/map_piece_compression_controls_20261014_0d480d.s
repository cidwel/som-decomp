.setcpu "65816"
.segment "CODE"
.org $480D
map_control_0d480d:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
