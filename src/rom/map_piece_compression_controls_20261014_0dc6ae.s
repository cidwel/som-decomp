.setcpu "65816"
.segment "CODE"
.org $C6AE
map_control_0dc6ae:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
