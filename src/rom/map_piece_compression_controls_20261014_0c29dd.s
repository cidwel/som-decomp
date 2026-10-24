.setcpu "65816"
.segment "CODE"
.org $29DD
map_control_0c29dd:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
