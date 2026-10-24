.setcpu "65816"
.segment "CODE"
.org $EEDF
map_control_0deedf:
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
