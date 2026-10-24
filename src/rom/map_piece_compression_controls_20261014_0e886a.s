.setcpu "65816"
.segment "CODE"
.org $886A
map_control_0e886a:
    .byte $E5 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
