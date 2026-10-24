.setcpu "65816"
.segment "CODE"
.org $1B5B
map_control_0d1b5b:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
