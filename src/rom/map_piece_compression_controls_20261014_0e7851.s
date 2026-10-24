.setcpu "65816"
.segment "CODE"
.org $7851
map_control_0e7851:
    .byte $E0 ; previous-row copy escape
    .byte $A5 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
