.setcpu "65816"
.segment "CODE"
.org $0E0C
map_control_0c0e0c:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
