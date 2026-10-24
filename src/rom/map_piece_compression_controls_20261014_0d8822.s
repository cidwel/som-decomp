.setcpu "65816"
.segment "CODE"
.org $8822
map_control_0d8822:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $79 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $29 ; distance low bit/count
