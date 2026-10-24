.setcpu "65816"
.segment "CODE"
.org $BDC6
map_control_0fbdc6:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C4 ; same-value copy count/distance
