.setcpu "65816"
.segment "CODE"
.org $BA35
map_control_0fba35:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
