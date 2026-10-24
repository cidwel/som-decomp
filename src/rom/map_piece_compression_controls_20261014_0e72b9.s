.setcpu "65816"
.segment "CODE"
.org $72B9
map_control_0e72b9:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
