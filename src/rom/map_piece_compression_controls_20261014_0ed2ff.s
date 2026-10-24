.setcpu "65816"
.segment "CODE"
.org $D2FF
map_control_0ed2ff:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
