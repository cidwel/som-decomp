.setcpu "65816"
.segment "CODE"
.org $CC7F
map_control_0fcc7f:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
