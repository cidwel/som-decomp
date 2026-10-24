.setcpu "65816"
.segment "CODE"
.org $88DD
map_control_0f88dd:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
