.setcpu "65816"
.segment "CODE"
.org $D8C0
map_control_0fd8c0:
    .byte $C6 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $C7 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
