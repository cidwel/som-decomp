.setcpu "65816"
.segment "CODE"
.org $AA02
map_control_0eaa02:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
