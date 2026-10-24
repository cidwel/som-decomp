.setcpu "65816"
.segment "CODE"
.org $3970
map_control_0d3970:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
