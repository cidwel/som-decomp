.setcpu "65816"
.segment "CODE"
.org $617D
map_control_0f617d:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
