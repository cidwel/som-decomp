.setcpu "65816"
.segment "CODE"
.org $F2A3
map_control_0df2a3:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
