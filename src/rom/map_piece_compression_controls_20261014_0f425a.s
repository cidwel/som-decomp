.setcpu "65816"
.segment "CODE"
.org $425A
map_control_0f425a:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
