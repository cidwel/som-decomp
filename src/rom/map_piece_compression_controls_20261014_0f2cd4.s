.setcpu "65816"
.segment "CODE"
.org $2CD4
map_control_0f2cd4:
    .byte $E0 ; previous-row copy escape
    .byte $9D ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
