.setcpu "65816"
.segment "CODE"
.org $DD6A
map_control_0ddd6a:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
