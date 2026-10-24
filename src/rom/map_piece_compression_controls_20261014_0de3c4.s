.setcpu "65816"
.segment "CODE"
.org $E3C4
map_control_0de3c4:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
