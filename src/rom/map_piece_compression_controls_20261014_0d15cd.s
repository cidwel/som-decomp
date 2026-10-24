.setcpu "65816"
.segment "CODE"
.org $15CD
map_control_0d15cd:
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
