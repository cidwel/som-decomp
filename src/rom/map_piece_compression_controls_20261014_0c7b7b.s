.setcpu "65816"
.segment "CODE"
.org $7B7B
map_control_0c7b7b:
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
