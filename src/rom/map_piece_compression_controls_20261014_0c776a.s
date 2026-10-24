.setcpu "65816"
.segment "CODE"
.org $776A
map_control_0c776a:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
