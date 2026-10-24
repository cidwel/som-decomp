.setcpu "65816"
.segment "CODE"
.org $D325
map_control_0ed325:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
