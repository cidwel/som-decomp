.setcpu "65816"
.segment "CODE"
.org $683D
map_control_0d683d:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
