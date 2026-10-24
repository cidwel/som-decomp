.setcpu "65816"
.segment "CODE"
.org $3A9B
map_control_0c3a9b:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
