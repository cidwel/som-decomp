.setcpu "65816"
.segment "CODE"
.org $EA42
map_control_0eea42:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $37 ; row-distance/count
