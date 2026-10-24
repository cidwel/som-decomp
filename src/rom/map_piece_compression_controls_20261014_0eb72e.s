.setcpu "65816"
.segment "CODE"
.org $B72E
map_control_0eb72e:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
