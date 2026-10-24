.setcpu "65816"
.segment "CODE"
.org $1994
map_control_0c1994:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
