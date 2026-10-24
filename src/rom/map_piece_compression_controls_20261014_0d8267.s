.setcpu "65816"
.segment "CODE"
.org $8267
map_control_0d8267:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
