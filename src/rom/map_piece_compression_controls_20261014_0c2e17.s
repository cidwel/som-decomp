.setcpu "65816"
.segment "CODE"
.org $2E17
map_control_0c2e17:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
