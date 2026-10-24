.setcpu "65816"
.segment "CODE"
.org $5464
map_control_0e5464:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
