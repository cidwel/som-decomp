.setcpu "65816"
.segment "CODE"
.org $CDCF
map_control_0dcdcf:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
