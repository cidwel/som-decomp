.setcpu "65816"
.segment "CODE"
.org $AA22
map_control_0faa22:
    .byte $C1 ; same-value copy count/distance
    .byte $D9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
