.setcpu "65816"
.segment "CODE"
.org $88BA
map_control_0c88ba:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
