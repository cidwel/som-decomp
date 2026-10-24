.setcpu "65816"
.segment "CODE"
.org $DEBD
map_control_0fdebd:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
