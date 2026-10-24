.setcpu "65816"
.segment "CODE"
.org $562F
map_control_0d562f:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
