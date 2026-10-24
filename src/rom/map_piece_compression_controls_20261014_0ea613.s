.setcpu "65816"
.segment "CODE"
.org $A613
map_control_0ea613:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
