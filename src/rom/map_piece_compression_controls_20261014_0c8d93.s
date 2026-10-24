.setcpu "65816"
.segment "CODE"
.org $8D93
map_control_0c8d93:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C1 ; same-value copy count/distance
