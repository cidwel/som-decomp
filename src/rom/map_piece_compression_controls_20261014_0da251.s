.setcpu "65816"
.segment "CODE"
.org $A251
map_control_0da251:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
