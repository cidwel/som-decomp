.setcpu "65816"
.segment "CODE"
.org $85C7
map_control_0e85c7:
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
