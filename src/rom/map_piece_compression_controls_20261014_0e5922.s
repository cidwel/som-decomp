.setcpu "65816"
.segment "CODE"
.org $5922
map_control_0e5922:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
