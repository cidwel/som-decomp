.setcpu "65816"
.segment "CODE"
.org $5D5E
map_control_0d5d5e:
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
    .byte $C2 ; same-value copy count/distance
