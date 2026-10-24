.setcpu "65816"
.segment "CODE"
.org $EACD
map_control_0deacd:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
