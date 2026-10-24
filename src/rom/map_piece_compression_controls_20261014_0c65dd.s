.setcpu "65816"
.segment "CODE"
.org $65DD
map_control_0c65dd:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
