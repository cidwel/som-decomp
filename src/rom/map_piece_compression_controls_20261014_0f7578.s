.setcpu "65816"
.segment "CODE"
.org $7578
map_control_0f7578:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
