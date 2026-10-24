.setcpu "65816"
.segment "CODE"
.org $838E
map_control_0d838e:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $44 ; row-distance/count
