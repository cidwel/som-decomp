.setcpu "65816"
.segment "CODE"
.org $F48E
map_control_0ff48e:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $37 ; row-distance/count
