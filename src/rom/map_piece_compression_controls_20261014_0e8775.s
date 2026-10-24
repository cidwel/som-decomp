.setcpu "65816"
.segment "CODE"
.org $8775
map_control_0e8775:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
