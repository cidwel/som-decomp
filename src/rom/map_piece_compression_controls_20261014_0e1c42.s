.setcpu "65816"
.segment "CODE"
.org $1C42
map_control_0e1c42:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
