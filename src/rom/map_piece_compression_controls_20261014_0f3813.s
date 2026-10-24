.setcpu "65816"
.segment "CODE"
.org $3813
map_control_0f3813:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
