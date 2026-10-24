.setcpu "65816"
.segment "CODE"
.org $7B4F
map_control_0e7b4f:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
