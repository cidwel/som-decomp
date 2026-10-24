.setcpu "65816"
.segment "CODE"
.org $3886
map_control_0f3886:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
