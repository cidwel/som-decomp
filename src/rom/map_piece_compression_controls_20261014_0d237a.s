.setcpu "65816"
.segment "CODE"
.org $237A
map_control_0d237a:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
