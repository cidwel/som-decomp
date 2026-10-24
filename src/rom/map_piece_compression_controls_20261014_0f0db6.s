.setcpu "65816"
.segment "CODE"
.org $0DB6
map_control_0f0db6:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
