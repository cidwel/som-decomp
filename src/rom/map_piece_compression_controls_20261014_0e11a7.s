.setcpu "65816"
.segment "CODE"
.org $11A7
map_control_0e11a7:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C2 ; same-value copy count/distance
