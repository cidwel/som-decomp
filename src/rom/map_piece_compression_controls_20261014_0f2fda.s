.setcpu "65816"
.segment "CODE"
.org $2FDA
map_control_0f2fda:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
