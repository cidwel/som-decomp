.setcpu "65816"
.segment "CODE"
.org $7BCB
map_control_0d7bcb:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
