.setcpu "65816"
.segment "CODE"
.org $5694
map_control_0d5694:
    .byte $CB ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
    .byte $C2 ; same-value copy count/distance
