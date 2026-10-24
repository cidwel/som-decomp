.setcpu "65816"
.segment "CODE"
.org $535E
map_control_0e535e:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
