.setcpu "65816"
.segment "CODE"
.org $5E43
map_control_0f5e43:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
