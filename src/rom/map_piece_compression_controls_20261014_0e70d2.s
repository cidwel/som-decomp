.setcpu "65816"
.segment "CODE"
.org $70D2
map_control_0e70d2:
    .byte $D2 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
