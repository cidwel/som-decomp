.setcpu "65816"
.segment "CODE"
.org $AB60
map_control_0fab60:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
