.setcpu "65816"
.segment "CODE"
.org $F1EF
map_control_0ef1ef:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $3F ; distance low bit/count
