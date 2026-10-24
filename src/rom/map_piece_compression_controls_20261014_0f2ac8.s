.setcpu "65816"
.segment "CODE"
.org $2AC8
map_control_0f2ac8:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
