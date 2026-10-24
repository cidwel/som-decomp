.setcpu "65816"
.segment "CODE"
.org $A7E5
map_control_0fa7e5:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
