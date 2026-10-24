.setcpu "65816"
.segment "CODE"
.org $5EF9
map_control_0c5ef9:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
