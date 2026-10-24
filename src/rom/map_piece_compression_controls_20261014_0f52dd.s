.setcpu "65816"
.segment "CODE"
.org $52DD
map_control_0f52dd:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
