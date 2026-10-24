.setcpu "65816"
.segment "CODE"
.org $22CF
map_control_0d22cf:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
