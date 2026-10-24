.setcpu "65816"
.segment "CODE"
.org $6819
map_control_0c6819:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
