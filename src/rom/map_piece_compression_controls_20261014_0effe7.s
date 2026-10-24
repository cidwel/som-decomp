.setcpu "65816"
.segment "CODE"
.org $FFE7
map_control_0effe7:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
