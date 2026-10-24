.setcpu "65816"
.segment "CODE"
.org $ACAB
map_control_0facab:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
