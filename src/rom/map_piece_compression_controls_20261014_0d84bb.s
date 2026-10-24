.setcpu "65816"
.segment "CODE"
.org $84BB
map_control_0d84bb:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
