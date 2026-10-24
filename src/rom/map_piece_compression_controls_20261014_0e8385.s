.setcpu "65816"
.segment "CODE"
.org $8385
map_control_0e8385:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
