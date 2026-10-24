.setcpu "65816"
.segment "CODE"
.org $5D4E
map_control_0d5d4e:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
