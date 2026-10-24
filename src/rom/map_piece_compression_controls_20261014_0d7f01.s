.setcpu "65816"
.segment "CODE"
.org $7F01
map_control_0d7f01:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C1 ; same-value copy count/distance
