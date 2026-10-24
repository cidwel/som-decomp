.setcpu "65816"
.segment "CODE"
.org $5576
map_control_0d5576:
    .byte $C7 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
