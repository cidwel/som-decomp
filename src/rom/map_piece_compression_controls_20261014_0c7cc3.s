.setcpu "65816"
.segment "CODE"
.org $7CC3
map_control_0c7cc3:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
