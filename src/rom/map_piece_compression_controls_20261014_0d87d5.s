.setcpu "65816"
.segment "CODE"
.org $87D5
map_control_0d87d5:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
    .byte $C1 ; same-value copy count/distance
