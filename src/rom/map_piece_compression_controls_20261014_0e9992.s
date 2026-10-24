.setcpu "65816"
.segment "CODE"
.org $9992
map_control_0e9992:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
