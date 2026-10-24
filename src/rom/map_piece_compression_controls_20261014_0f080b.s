.setcpu "65816"
.segment "CODE"
.org $080B
map_control_0f080b:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
