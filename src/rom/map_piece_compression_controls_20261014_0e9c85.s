.setcpu "65816"
.segment "CODE"
.org $9C85
map_control_0e9c85:
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count
    .byte $C2 ; same-value copy count/distance
