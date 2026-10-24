.setcpu "65816"
.segment "CODE"
.org $A330
map_control_0da330:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
