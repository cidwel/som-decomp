.setcpu "65816"
.segment "CODE"
.org $DCC2
map_control_0edcc2:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
