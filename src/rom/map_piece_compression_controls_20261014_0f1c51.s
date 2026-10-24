.setcpu "65816"
.segment "CODE"
.org $1C51
map_control_0f1c51:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
