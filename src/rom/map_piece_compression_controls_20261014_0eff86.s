.setcpu "65816"
.segment "CODE"
.org $FF86
map_control_0eff86:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
