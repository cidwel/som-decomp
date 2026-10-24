.setcpu "65816"
.segment "CODE"
.org $BD7D
map_control_0ebd7d:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C1 ; same-value copy count/distance
