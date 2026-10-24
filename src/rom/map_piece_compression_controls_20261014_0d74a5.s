.setcpu "65816"
.segment "CODE"
.org $74A5
map_control_0d74a5:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
