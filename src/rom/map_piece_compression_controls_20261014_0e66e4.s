.setcpu "65816"
.segment "CODE"
.org $66E4
map_control_0e66e4:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
    .byte $C1 ; same-value copy count/distance
