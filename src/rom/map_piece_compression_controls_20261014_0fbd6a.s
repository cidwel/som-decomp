.setcpu "65816"
.segment "CODE"
.org $BD6A
map_control_0fbd6a:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
