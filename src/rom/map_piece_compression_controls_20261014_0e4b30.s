.setcpu "65816"
.segment "CODE"
.org $4B30
map_control_0e4b30:
    .byte $E0 ; previous-row copy escape
    .byte $AC ; row-distance/count
