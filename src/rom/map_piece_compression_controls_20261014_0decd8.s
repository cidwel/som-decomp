.setcpu "65816"
.segment "CODE"
.org $ECD8
map_control_0decd8:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
