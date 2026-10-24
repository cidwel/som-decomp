.setcpu "65816"
.segment "CODE"
.org $6327
map_control_0d6327:
    .byte $E4 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
