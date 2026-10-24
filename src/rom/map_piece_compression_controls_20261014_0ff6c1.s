.setcpu "65816"
.segment "CODE"
.org $F6C1
map_control_0ff6c1:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
