.setcpu "65816"
.segment "CODE"
.org $940A
map_control_0e940a:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
