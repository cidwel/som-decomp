.setcpu "65816"
.segment "CODE"
.org $7A9E
map_control_0d7a9e:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
