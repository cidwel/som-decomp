.setcpu "65816"
.segment "CODE"
.org $8475
map_control_0e8475:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
