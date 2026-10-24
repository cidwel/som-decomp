.setcpu "65816"
.segment "CODE"
.org $01E4
map_control_0f01e4:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
