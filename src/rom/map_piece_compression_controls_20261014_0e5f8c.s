.setcpu "65816"
.segment "CODE"
.org $5F8C
map_control_0e5f8c:
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
