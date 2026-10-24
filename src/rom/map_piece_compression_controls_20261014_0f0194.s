.setcpu "65816"
.segment "CODE"
.org $0194
map_control_0f0194:
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $BB ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
