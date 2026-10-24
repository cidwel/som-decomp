.setcpu "65816"
.segment "CODE"
.org $3BA0
map_control_0c3ba0:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
