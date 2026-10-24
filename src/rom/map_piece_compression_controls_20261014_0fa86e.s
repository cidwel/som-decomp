.setcpu "65816"
.segment "CODE"
.org $A86E
map_control_0fa86e:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
