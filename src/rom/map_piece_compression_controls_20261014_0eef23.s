.setcpu "65816"
.segment "CODE"
.org $EF23
map_control_0eef23:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
