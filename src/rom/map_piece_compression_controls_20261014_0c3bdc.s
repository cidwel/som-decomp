.setcpu "65816"
.segment "CODE"
.org $3BDC
map_control_0c3bdc:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
