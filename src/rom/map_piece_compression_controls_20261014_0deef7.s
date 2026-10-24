.setcpu "65816"
.segment "CODE"
.org $EEF7
map_control_0deef7:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
