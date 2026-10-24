.setcpu "65816"
.segment "CODE"
.org $1DC5
map_control_0f1dc5:
    .byte $C1 ; same-value copy count/distance
    .byte $DF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
