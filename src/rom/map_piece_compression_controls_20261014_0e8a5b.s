.setcpu "65816"
.segment "CODE"
.org $8A5B
map_control_0e8a5b:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
