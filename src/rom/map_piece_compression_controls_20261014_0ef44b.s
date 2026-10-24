.setcpu "65816"
.segment "CODE"
.org $F44B
map_control_0ef44b:
    .byte $E0 ; previous-row copy escape
    .byte $AF ; row-distance/count
    .byte $C5 ; same-value copy count/distance
