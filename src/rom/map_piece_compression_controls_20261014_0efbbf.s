.setcpu "65816"
.segment "CODE"
.org $FBBF
map_control_0efbbf:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
