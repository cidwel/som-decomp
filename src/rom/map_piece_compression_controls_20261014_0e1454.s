.setcpu "65816"
.segment "CODE"
.org $1454
map_control_0e1454:
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
