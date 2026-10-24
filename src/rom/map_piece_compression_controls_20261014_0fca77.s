.setcpu "65816"
.segment "CODE"
.org $CA77
map_control_0fca77:
    .byte $E5 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
