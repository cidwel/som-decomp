.setcpu "65816"
.segment "CODE"
.org $5F0C
map_control_0d5f0c:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
