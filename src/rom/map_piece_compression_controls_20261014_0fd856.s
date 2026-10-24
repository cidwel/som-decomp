.setcpu "65816"
.segment "CODE"
.org $D856
map_control_0fd856:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
