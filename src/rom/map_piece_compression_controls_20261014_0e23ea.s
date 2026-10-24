.setcpu "65816"
.segment "CODE"
.org $23EA
map_control_0e23ea:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
