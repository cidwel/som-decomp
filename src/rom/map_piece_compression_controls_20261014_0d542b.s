.setcpu "65816"
.segment "CODE"
.org $542B
map_control_0d542b:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
