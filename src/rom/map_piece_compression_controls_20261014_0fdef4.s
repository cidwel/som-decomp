.setcpu "65816"
.segment "CODE"
.org $DEF4
map_control_0fdef4:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
