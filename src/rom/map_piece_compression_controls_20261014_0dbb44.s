.setcpu "65816"
.segment "CODE"
.org $BB44
map_control_0dbb44:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
