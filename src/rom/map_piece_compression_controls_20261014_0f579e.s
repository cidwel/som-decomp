.setcpu "65816"
.segment "CODE"
.org $579E
map_control_0f579e:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
