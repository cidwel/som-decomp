.setcpu "65816"
.segment "CODE"
.org $A6F4
map_control_0ea6f4:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $B3 ; row-distance/count
