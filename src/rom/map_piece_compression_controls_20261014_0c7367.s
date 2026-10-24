.setcpu "65816"
.segment "CODE"
.org $7367
map_control_0c7367:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
