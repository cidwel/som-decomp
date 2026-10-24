.setcpu "65816"
.segment "CODE"
.org $249D
map_control_0e249d:
    .byte $D7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
