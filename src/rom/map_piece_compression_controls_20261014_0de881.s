.setcpu "65816"
.segment "CODE"
.org $E881
map_control_0de881:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
