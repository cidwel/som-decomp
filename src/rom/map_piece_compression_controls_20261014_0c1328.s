.setcpu "65816"
.segment "CODE"
.org $1328
map_control_0c1328:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
