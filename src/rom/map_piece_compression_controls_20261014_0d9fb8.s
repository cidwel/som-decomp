.setcpu "65816"
.segment "CODE"
.org $9FB8
map_control_0d9fb8:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
