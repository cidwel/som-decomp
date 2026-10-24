.setcpu "65816"
.segment "CODE"
.org $8A90
map_control_0c8a90:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
