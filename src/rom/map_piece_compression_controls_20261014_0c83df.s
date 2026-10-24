.setcpu "65816"
.segment "CODE"
.org $83DF
map_control_0c83df:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
    .byte $E2 ; previous-row copy count
