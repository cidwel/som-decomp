.setcpu "65816"
.segment "CODE"
.org $9E66
map_control_0d9e66:
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
