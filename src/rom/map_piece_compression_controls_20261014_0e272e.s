.setcpu "65816"
.segment "CODE"
.org $272E
map_control_0e272e:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
