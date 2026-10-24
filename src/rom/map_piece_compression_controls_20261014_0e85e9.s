.setcpu "65816"
.segment "CODE"
.org $85E9
map_control_0e85e9:
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
