.setcpu "65816"
.segment "CODE"
.org $D3E7
map_control_0dd3e7:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
