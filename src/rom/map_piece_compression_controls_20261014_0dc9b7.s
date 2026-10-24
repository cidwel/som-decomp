.setcpu "65816"
.segment "CODE"
.org $C9B7
map_control_0dc9b7:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
