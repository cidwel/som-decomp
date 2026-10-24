.setcpu "65816"
.segment "CODE"
.org $7626
map_control_0e7626:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C6 ; same-value copy count/distance
