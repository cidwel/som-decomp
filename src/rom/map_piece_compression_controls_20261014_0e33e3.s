.setcpu "65816"
.segment "CODE"
.org $33E3
map_control_0e33e3:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
