.setcpu "65816"
.segment "CODE"
.org $BB52
map_control_0ebb52:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
