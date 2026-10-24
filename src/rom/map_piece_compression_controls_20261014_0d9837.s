.setcpu "65816"
.segment "CODE"
.org $9837
map_control_0d9837:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
