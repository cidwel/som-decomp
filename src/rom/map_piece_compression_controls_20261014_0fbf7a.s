.setcpu "65816"
.segment "CODE"
.org $BF7A
map_control_0fbf7a:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
