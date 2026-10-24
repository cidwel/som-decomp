.setcpu "65816"
.segment "CODE"
.org $6DCD
map_control_0c6dcd:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
