.setcpu "65816"
.segment "CODE"
.org $FAC0
map_control_0efac0:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $A0 ; row-distance/count
