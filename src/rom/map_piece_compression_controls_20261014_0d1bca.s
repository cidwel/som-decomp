.setcpu "65816"
.segment "CODE"
.org $1BCA
map_control_0d1bca:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $A3 ; row-distance/count
