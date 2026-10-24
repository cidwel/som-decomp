.setcpu "65816"
.segment "CODE"
.org $58B2
map_control_0d58b2:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
