.setcpu "65816"
.segment "CODE"
.org $B8F2
map_control_0fb8f2:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
