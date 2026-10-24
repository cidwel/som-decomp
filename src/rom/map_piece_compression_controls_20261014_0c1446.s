.setcpu "65816"
.segment "CODE"
.org $1446
map_control_0c1446:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
