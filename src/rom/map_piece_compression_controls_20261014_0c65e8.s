.setcpu "65816"
.segment "CODE"
.org $65E8
map_control_0c65e8:
    .byte $D2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
