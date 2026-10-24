.setcpu "65816"
.segment "CODE"
.org $FB71
map_control_0ffb71:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
