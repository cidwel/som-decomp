.setcpu "65816"
.segment "CODE"
.org $3B83
map_control_0c3b83:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
