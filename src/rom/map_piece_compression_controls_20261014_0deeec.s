.setcpu "65816"
.segment "CODE"
.org $EEEC
map_control_0deeec:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
