.setcpu "65816"
.segment "CODE"
.org $1677
map_control_0d1677:
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
