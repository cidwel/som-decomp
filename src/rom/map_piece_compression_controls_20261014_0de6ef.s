.setcpu "65816"
.segment "CODE"
.org $E6EF
map_control_0de6ef:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
