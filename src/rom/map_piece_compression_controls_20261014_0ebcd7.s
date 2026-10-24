.setcpu "65816"
.segment "CODE"
.org $BCD7
map_control_0ebcd7:
    .byte $E0 ; previous-row copy escape
    .byte $98 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
