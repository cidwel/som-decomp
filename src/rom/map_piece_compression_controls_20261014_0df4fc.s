.setcpu "65816"
.segment "CODE"
.org $F4FC
map_control_0df4fc:
    .byte $CC ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
