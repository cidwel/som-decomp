.setcpu "65816"
.segment "CODE"
.org $2E6B
map_control_0c2e6b:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
