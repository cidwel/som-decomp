.setcpu "65816"
.segment "CODE"
.org $FDE7
map_control_0efde7:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $D2 ; same-value copy count/distance
