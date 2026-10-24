.setcpu "65816"
.segment "CODE"
.org $0372
map_control_0e0372:
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
