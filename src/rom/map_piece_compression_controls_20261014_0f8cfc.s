.setcpu "65816"
.segment "CODE"
.org $8CFC
map_control_0f8cfc:
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
