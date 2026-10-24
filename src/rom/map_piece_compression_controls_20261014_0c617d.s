.setcpu "65816"
.segment "CODE"
.org $617D
map_control_0c617d:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
