.setcpu "65816"
.segment "CODE"
.org $63D0
map_control_0f63d0:
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
