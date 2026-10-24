.setcpu "65816"
.segment "CODE"
.org $BD26
map_control_0dbd26:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
