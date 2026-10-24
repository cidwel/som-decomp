.setcpu "65816"
.segment "CODE"
.org $1422
map_control_0e1422:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
