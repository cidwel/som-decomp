.setcpu "65816"
.segment "CODE"
.org $945E
map_control_0e945e:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $A3 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
