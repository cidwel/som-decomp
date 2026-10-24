.setcpu "65816"
.segment "CODE"
.org $BE66
map_control_0dbe66:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
