.setcpu "65816"
.segment "CODE"
.org $DEFC
map_control_0fdefc:
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
