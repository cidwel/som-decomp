.setcpu "65816"
.segment "CODE"
.org $589D
map_control_0d589d:
    .byte $D5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
