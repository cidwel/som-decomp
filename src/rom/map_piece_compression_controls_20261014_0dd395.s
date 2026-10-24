.setcpu "65816"
.segment "CODE"
.org $D395
map_control_0dd395:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
