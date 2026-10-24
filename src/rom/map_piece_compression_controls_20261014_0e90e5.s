.setcpu "65816"
.segment "CODE"
.org $90E5
map_control_0e90e5:
    .byte $E0 ; previous-row copy escape
    .byte $AC ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $55 ; row-distance/count
