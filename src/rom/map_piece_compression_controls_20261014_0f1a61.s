.setcpu "65816"
.segment "CODE"
.org $1A61
map_control_0f1a61:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
