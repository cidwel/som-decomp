.setcpu "65816"
.segment "CODE"
.org $8A43
map_control_0e8a43:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
