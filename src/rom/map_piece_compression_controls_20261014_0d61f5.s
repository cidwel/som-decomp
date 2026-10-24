.setcpu "65816"
.segment "CODE"
.org $61F5
map_control_0d61f5:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
