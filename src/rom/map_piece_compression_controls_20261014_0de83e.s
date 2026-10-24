.setcpu "65816"
.segment "CODE"
.org $E83E
map_control_0de83e:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
