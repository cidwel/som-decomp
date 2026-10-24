.setcpu "65816"
.segment "CODE"
.org $F57C
map_control_0df57c:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
