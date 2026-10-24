.setcpu "65816"
.segment "CODE"
.org $F3EC
map_control_0df3ec:
    .byte $CB ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
