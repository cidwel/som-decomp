.setcpu "65816"
.segment "CODE"
.org $6231
map_control_0d6231:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
