.setcpu "65816"
.segment "CODE"
.org $2F61
map_control_0d2f61:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
