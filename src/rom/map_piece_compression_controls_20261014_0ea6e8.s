.setcpu "65816"
.segment "CODE"
.org $A6E8
map_control_0ea6e8:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
