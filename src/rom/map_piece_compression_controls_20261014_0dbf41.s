.setcpu "65816"
.segment "CODE"
.org $BF41
map_control_0dbf41:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
    .byte $C2 ; same-value copy count/distance
