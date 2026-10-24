.setcpu "65816"
.segment "CODE"
.org $D62D
map_control_0fd62d:
    .byte $E5 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
