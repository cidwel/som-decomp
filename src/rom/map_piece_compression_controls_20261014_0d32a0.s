.setcpu "65816"
.segment "CODE"
.org $32A0
map_control_0d32a0:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
