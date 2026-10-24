.setcpu "65816"
.segment "CODE"
.org $22DC
map_control_0c22dc:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C1 ; same-value copy count/distance
