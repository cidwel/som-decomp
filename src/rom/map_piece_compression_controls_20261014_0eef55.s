.setcpu "65816"
.segment "CODE"
.org $EF55
map_control_0eef55:
    .byte $E2 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
