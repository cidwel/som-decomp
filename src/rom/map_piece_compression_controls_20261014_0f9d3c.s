.setcpu "65816"
.segment "CODE"
.org $9D3C
map_control_0f9d3c:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
