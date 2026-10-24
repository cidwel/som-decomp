.setcpu "65816"
.segment "CODE"
.org $8B18
map_control_0c8b18:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
