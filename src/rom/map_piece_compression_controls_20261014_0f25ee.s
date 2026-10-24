.setcpu "65816"
.segment "CODE"
.org $25EE
map_control_0f25ee:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
