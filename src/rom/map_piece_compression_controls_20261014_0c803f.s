.setcpu "65816"
.segment "CODE"
.org $803F
map_control_0c803f:
    .byte $EC ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
