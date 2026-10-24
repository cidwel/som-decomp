.setcpu "65816"
.segment "CODE"
.org $C0D3
map_control_0ec0d3:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
