.setcpu "65816"
.segment "CODE"
.org $A5C6
map_control_0ea5c6:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
