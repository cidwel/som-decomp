.setcpu "65816"
.segment "CODE"
.org $2974
map_control_0e2974:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
