.setcpu "65816"
.segment "CODE"
.org $7A4C
map_control_0d7a4c:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
