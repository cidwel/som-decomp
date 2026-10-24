.setcpu "65816"
.segment "CODE"
.org $B2ED
map_control_0eb2ed:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
