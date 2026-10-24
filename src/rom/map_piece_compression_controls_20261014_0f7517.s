.setcpu "65816"
.segment "CODE"
.org $7517
map_control_0f7517:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
