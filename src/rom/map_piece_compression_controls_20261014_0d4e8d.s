.setcpu "65816"
.segment "CODE"
.org $4E8D
map_control_0d4e8d:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
