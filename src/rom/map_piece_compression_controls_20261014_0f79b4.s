.setcpu "65816"
.segment "CODE"
.org $79B4
map_control_0f79b4:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
