.setcpu "65816"
.segment "CODE"
.org $6DB8
map_control_0d6db8:
    .byte $E5 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E6 ; previous-row copy count
