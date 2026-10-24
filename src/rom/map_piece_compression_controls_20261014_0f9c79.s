.setcpu "65816"
.segment "CODE"
.org $9C79
map_control_0f9c79:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
