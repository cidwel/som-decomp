.setcpu "65816"
.segment "CODE"
.org $7BD4
map_control_0c7bd4:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
