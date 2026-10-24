.setcpu "65816"
.segment "CODE"
.org $F118
map_control_0df118:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
