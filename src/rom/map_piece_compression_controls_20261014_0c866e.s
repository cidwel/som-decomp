.setcpu "65816"
.segment "CODE"
.org $866E
map_control_0c866e:
    .byte $E0 ; previous-row copy escape
    .byte $B6 ; row-distance/count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $98 ; row-distance/count
