.setcpu "65816"
.segment "CODE"
.org $2DBD
map_control_0e2dbd:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
