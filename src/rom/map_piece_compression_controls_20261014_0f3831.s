.setcpu "65816"
.segment "CODE"
.org $3831
map_control_0f3831:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
