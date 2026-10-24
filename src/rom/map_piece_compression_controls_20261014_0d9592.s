.setcpu "65816"
.segment "CODE"
.org $9592
map_control_0d9592:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
