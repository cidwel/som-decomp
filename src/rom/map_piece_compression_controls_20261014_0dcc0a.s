.setcpu "65816"
.segment "CODE"
.org $CC0A
map_control_0dcc0a:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
