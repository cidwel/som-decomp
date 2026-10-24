.setcpu "65816"
.segment "CODE"
.org $CCD6
map_control_0eccd6:
    .byte $D3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
