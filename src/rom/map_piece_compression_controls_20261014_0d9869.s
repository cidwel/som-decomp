.setcpu "65816"
.segment "CODE"
.org $9869
map_control_0d9869:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
