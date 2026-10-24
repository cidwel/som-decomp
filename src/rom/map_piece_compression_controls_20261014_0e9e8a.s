.setcpu "65816"
.segment "CODE"
.org $9E8A
map_control_0e9e8a:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
