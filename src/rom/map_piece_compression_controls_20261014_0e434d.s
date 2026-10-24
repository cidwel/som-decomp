.setcpu "65816"
.segment "CODE"
.org $434D
map_control_0e434d:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
