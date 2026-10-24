.setcpu "65816"
.segment "CODE"
.org $D04A
map_control_0ed04a:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
