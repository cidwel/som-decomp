.setcpu "65816"
.segment "CODE"
.org $23A2
map_control_0d23a2:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
