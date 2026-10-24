.setcpu "65816"
.segment "CODE"
.org $600E
map_control_0d600e:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
