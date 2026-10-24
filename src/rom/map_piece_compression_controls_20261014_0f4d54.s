.setcpu "65816"
.segment "CODE"
.org $4D54
map_control_0f4d54:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $42 ; distance low bit/count
