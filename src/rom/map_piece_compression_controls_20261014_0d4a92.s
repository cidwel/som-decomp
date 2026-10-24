.setcpu "65816"
.segment "CODE"
.org $4A92
map_control_0d4a92:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C1 ; same-value copy count/distance
