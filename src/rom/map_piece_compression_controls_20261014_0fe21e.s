.setcpu "65816"
.segment "CODE"
.org $E21E
map_control_0fe21e:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
