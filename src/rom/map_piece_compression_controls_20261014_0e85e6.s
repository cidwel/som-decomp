.setcpu "65816"
.segment "CODE"
.org $85E6
map_control_0e85e6:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
