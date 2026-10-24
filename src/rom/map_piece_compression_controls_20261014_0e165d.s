.setcpu "65816"
.segment "CODE"
.org $165D
map_control_0e165d:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
