.setcpu "65816"
.segment "CODE"
.org $EEBA
map_control_0deeba:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
