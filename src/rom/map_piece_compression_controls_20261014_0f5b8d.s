.setcpu "65816"
.segment "CODE"
.org $5B8D
map_control_0f5b8d:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
