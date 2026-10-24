.setcpu "65816"
.segment "CODE"
.org $40B3
map_control_0e40b3:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C5 ; same-value copy count/distance
