.setcpu "65816"
.segment "CODE"
.org $1076
map_control_0e1076:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
