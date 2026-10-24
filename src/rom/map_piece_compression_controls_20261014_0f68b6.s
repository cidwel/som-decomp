.setcpu "65816"
.segment "CODE"
.org $68B6
map_control_0f68b6:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
