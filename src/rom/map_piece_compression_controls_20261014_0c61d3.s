.setcpu "65816"
.segment "CODE"
.org $61D3
map_control_0c61d3:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
