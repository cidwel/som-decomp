.setcpu "65816"
.segment "CODE"
.org $5B07
map_control_0d5b07:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
