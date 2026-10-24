.setcpu "65816"
.segment "CODE"
.org $1AE3
map_control_0c1ae3:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $C1 ; same-value copy count/distance
