.setcpu "65816"
.segment "CODE"
.org $2644
map_control_0d2644:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
