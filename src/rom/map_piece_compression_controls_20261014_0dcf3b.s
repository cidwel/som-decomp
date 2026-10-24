.setcpu "65816"
.segment "CODE"
.org $CF3B
map_control_0dcf3b:
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count
