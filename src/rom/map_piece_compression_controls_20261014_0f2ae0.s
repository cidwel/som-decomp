.setcpu "65816"
.segment "CODE"
.org $2AE0
map_control_0f2ae0:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
