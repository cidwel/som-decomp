.setcpu "65816"
.segment "CODE"
.org $0229
map_control_0f0229:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
