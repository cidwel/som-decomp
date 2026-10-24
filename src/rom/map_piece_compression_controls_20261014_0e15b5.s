.setcpu "65816"
.segment "CODE"
.org $15B5
map_control_0e15b5:
    .byte $E3 ; previous-row copy count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
