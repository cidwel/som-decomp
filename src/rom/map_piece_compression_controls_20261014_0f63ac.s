.setcpu "65816"
.segment "CODE"
.org $63AC
map_control_0f63ac:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
