.setcpu "65816"
.segment "CODE"
.org $9815
map_control_0d9815:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
