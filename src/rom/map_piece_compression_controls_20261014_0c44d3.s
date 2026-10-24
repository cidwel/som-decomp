.setcpu "65816"
.segment "CODE"
.org $44D3
map_control_0c44d3:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
