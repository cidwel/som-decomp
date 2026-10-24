.setcpu "65816"
.segment "CODE"
.org $68D2
map_control_0c68d2:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
