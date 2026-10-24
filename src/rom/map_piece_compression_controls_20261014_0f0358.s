.setcpu "65816"
.segment "CODE"
.org $0358
map_control_0f0358:
    .byte $C4 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E6 ; previous-row copy count
