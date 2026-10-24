.setcpu "65816"
.segment "CODE"
.org $3385
map_control_0d3385:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
