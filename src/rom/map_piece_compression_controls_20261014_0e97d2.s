.setcpu "65816"
.segment "CODE"
.org $97D2
map_control_0e97d2:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
