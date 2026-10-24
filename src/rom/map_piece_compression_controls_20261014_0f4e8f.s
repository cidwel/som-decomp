.setcpu "65816"
.segment "CODE"
.org $4E8F
map_control_0f4e8f:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
