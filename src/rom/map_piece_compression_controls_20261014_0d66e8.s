.setcpu "65816"
.segment "CODE"
.org $66E8
map_control_0d66e8:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $CC ; same-value copy count/distance
