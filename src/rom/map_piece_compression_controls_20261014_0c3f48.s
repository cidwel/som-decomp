.setcpu "65816"
.segment "CODE"
.org $3F48
map_control_0c3f48:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
