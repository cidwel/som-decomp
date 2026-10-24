.setcpu "65816"
.segment "CODE"
.org $DD8B
map_control_0ddd8b:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
