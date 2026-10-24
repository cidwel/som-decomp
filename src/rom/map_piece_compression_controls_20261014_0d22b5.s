.setcpu "65816"
.segment "CODE"
.org $22B5
map_control_0d22b5:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
