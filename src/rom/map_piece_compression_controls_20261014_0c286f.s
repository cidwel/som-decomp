.setcpu "65816"
.segment "CODE"
.org $286F
map_control_0c286f:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
