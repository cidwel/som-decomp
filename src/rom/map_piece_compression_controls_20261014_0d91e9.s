.setcpu "65816"
.segment "CODE"
.org $91E9
map_control_0d91e9:
    .byte $E0 ; previous-row copy escape
    .byte $3E ; row-distance/count
