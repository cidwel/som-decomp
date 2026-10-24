.setcpu "65816"
.segment "CODE"
.org $7222
map_control_0c7222:
    .byte $DF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
