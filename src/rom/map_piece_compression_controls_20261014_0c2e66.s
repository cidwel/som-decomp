.setcpu "65816"
.segment "CODE"
.org $2E66
map_control_0c2e66:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
