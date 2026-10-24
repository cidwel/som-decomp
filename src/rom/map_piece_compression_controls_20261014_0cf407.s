.setcpu "65816"
.segment "CODE"
.org $F407
map_control_0cf407:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
