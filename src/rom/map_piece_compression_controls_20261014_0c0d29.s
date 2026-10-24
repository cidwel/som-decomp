.setcpu "65816"
.segment "CODE"
.org $0D29
map_control_0c0d29:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
