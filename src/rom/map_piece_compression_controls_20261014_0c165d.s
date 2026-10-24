.setcpu "65816"
.segment "CODE"
.org $165D
map_control_0c165d:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
