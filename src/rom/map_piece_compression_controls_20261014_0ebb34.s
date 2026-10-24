.setcpu "65816"
.segment "CODE"
.org $BB34
map_control_0ebb34:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
