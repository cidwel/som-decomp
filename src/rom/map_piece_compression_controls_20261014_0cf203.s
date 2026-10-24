.setcpu "65816"
.segment "CODE"
.org $F203
map_control_0cf203:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
