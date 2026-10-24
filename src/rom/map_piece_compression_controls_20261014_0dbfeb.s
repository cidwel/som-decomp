.setcpu "65816"
.segment "CODE"
.org $BFEB
map_control_0dbfeb:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
