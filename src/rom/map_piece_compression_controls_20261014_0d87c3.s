.setcpu "65816"
.segment "CODE"
.org $87C3
map_control_0d87c3:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
