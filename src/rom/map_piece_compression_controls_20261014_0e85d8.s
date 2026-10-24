.setcpu "65816"
.segment "CODE"
.org $85D8
map_control_0e85d8:
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
