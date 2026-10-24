.setcpu "65816"
.segment "CODE"
.org $2E4E
map_control_0d2e4e:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
