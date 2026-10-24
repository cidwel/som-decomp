.setcpu "65816"
.segment "CODE"
.org $A70B
map_control_0ea70b:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
