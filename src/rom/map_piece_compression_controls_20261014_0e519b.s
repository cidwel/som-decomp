.setcpu "65816"
.segment "CODE"
.org $519B
map_control_0e519b:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
