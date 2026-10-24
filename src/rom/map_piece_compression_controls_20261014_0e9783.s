.setcpu "65816"
.segment "CODE"
.org $9783
map_control_0e9783:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
