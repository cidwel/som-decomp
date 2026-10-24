.setcpu "65816"
.segment "CODE"
.org $3FBE
map_control_0d3fbe:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
