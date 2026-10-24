.setcpu "65816"
.segment "CODE"
.org $C7BD
map_control_0fc7bd:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
