.setcpu "65816"
.segment "CODE"
.org $FDBE
map_control_0efdbe:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
