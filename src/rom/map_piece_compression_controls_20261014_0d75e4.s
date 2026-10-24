.setcpu "65816"
.segment "CODE"
.org $75E4
map_control_0d75e4:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C2 ; same-value copy count/distance
