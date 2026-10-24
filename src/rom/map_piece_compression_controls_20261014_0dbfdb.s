.setcpu "65816"
.segment "CODE"
.org $BFDB
map_control_0dbfdb:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
