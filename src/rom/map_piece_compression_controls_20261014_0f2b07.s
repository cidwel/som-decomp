.setcpu "65816"
.segment "CODE"
.org $2B07
map_control_0f2b07:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
