.setcpu "65816"
.segment "CODE"
.org $EB7D
map_control_0eeb7d:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
