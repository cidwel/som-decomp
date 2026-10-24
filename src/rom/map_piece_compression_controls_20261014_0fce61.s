.setcpu "65816"
.segment "CODE"
.org $CE61
map_control_0fce61:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
