.setcpu "65816"
.segment "CODE"
.org $3E44
map_control_0d3e44:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
