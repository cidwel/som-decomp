.setcpu "65816"
.segment "CODE"
.org $16E0
map_control_0c16e0:
    .byte $E0 ; previous-row copy escape
    .byte $AC ; row-distance/count
