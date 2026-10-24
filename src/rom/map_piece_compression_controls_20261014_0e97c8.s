.setcpu "65816"
.segment "CODE"
.org $97C8
map_control_0e97c8:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
