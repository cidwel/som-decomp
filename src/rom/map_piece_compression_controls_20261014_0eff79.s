.setcpu "65816"
.segment "CODE"
.org $FF79
map_control_0eff79:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
