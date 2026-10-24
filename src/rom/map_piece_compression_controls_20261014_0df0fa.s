.setcpu "65816"
.segment "CODE"
.org $F0FA
map_control_0df0fa:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
