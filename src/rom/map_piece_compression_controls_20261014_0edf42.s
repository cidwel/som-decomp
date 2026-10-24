.setcpu "65816"
.segment "CODE"
.org $DF42
map_control_0edf42:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
