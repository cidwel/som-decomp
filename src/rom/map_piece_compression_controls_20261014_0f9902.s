.setcpu "65816"
.segment "CODE"
.org $9902
map_control_0f9902:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
