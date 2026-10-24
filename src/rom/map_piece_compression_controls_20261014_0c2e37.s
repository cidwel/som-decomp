.setcpu "65816"
.segment "CODE"
.org $2E37
map_control_0c2e37:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
