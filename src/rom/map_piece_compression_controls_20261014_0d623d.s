.setcpu "65816"
.segment "CODE"
.org $623D
map_control_0d623d:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
