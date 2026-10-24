.setcpu "65816"
.segment "CODE"
.org $1FAF
map_control_0c1faf:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
