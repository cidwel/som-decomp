.setcpu "65816"
.segment "CODE"
.org $85E2
map_control_0c85e2:
    .byte $E0 ; previous-row copy escape
    .byte $41 ; row-distance/count
