.setcpu "65816"
.segment "CODE"
.org $5717
map_control_0e5717:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
