.setcpu "65816"
.segment "CODE"
.org $13B0
map_control_0e13b0:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
