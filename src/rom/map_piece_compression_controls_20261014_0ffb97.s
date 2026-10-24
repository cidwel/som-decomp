.setcpu "65816"
.segment "CODE"
.org $FB97
map_control_0ffb97:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
