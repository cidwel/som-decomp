.setcpu "65816"
.segment "CODE"
.org $EFD8
map_control_0fefd8:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
