.setcpu "65816"
.segment "CODE"
.org $7F17
map_control_0f7f17:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
