.setcpu "65816"
.segment "CODE"
.org $5447
map_control_0c5447:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
