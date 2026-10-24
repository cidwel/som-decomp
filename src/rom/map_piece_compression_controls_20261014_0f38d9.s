.setcpu "65816"
.segment "CODE"
.org $38D9
map_control_0f38d9:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
