.setcpu "65816"
.segment "CODE"
.org $3E89
map_control_0f3e89:
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
    .byte $C6 ; same-value copy count/distance
