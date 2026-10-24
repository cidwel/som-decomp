.setcpu "65816"
.segment "CODE"
.org $45BF
map_control_0d45bf:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
