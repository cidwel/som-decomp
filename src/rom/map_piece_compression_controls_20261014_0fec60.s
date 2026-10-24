.setcpu "65816"
.segment "CODE"
.org $EC60
map_control_0fec60:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
