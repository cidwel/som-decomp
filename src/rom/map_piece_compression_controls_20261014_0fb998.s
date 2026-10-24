.setcpu "65816"
.segment "CODE"
.org $B998
map_control_0fb998:
    .byte $E9 ; backreference distance high bits
    .byte $D3 ; distance low bit/count
