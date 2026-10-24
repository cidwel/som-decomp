.setcpu "65816"
.segment "CODE"
.org $97DE
map_control_0e97de:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
