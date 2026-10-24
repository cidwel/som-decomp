.setcpu "65816"
.segment "CODE"
.org $8B4A
map_control_0c8b4a:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
