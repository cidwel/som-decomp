.setcpu "65816"
.segment "CODE"
.org $6BD4
map_control_0d6bd4:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
