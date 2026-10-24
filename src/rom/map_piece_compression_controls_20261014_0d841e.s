.setcpu "65816"
.segment "CODE"
.org $841E
map_control_0d841e:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $53 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $A0 ; row-distance/count
