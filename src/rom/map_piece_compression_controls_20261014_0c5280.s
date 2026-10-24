.setcpu "65816"
.segment "CODE"
.org $5280
map_control_0c5280:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
