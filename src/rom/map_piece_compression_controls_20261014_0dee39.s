.setcpu "65816"
.segment "CODE"
.org $EE39
map_control_0dee39:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
