.setcpu "65816"
.segment "CODE"
.org $CC85
map_control_0dcc85:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
