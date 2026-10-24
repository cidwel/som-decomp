.setcpu "65816"
.segment "CODE"
.org $2DE0
map_control_0c2de0:
    .byte $E0 ; previous-row copy escape
    .byte $9C ; row-distance/count
    .byte $C1 ; same-value copy count/distance
