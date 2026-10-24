.setcpu "65816"
.segment "CODE"
.org $33B1
map_control_0e33b1:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C4 ; same-value copy count/distance
