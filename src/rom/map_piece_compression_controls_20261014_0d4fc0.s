.setcpu "65816"
.segment "CODE"
.org $4FC0
map_control_0d4fc0:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
