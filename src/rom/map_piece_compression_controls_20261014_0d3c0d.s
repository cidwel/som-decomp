.setcpu "65816"
.segment "CODE"
.org $3C0D
map_control_0d3c0d:
    .byte $E0 ; previous-row copy escape
    .byte $A0 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
