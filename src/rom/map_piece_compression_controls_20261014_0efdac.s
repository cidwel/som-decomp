.setcpu "65816"
.segment "CODE"
.org $FDAC
map_control_0efdac:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
