.setcpu "65816"
.segment "CODE"
.org $0D3E
map_control_0e0d3e:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
