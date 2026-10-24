.setcpu "65816"
.segment "CODE"
.org $8D1A
map_control_0f8d1a:
    .byte $E0 ; previous-row copy escape
    .byte $C4 ; row-distance/count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count
