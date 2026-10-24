.setcpu "65816"
.segment "CODE"
.org $F070
map_control_0df070:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
