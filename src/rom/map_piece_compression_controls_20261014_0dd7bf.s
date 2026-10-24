.setcpu "65816"
.segment "CODE"
.org $D7BF
map_control_0dd7bf:
    .byte $E9 ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E1 ; previous-row copy count
