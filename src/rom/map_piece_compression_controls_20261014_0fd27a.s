.setcpu "65816"
.segment "CODE"
.org $D27A
map_control_0fd27a:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
