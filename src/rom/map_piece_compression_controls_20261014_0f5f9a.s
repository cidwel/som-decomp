.setcpu "65816"
.segment "CODE"
.org $5F9A
map_control_0f5f9a:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
