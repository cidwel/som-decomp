.setcpu "65816"
.segment "CODE"
.org $3744
map_control_0f3744:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
