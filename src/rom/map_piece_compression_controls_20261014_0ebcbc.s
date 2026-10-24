.setcpu "65816"
.segment "CODE"
.org $BCBC
map_control_0ebcbc:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $C2 ; same-value copy count/distance
