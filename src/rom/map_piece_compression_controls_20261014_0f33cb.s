.setcpu "65816"
.segment "CODE"
.org $33CB
map_control_0f33cb:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
