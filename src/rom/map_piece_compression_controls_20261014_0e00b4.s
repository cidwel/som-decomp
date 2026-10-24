.setcpu "65816"
.segment "CODE"
.org $00B4
map_control_0e00b4:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
