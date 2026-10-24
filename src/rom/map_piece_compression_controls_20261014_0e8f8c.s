.setcpu "65816"
.segment "CODE"
.org $8F8C
map_control_0e8f8c:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
