.setcpu "65816"
.segment "CODE"
.org $84DE
map_control_0e84de:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C3 ; same-value copy count/distance
