.setcpu "65816"
.segment "CODE"
.org $5645
map_control_0d5645:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
