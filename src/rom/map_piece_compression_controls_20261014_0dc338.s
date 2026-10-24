.setcpu "65816"
.segment "CODE"
.org $C338
map_control_0dc338:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
