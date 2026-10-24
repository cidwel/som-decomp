.setcpu "65816"
.segment "CODE"
.org $F37C
map_control_0df37c:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
