.setcpu "65816"
.segment "CODE"
.org $7A33
map_control_0d7a33:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
