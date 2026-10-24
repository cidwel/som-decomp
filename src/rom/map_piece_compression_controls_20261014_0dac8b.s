.setcpu "65816"
.segment "CODE"
.org $AC8B
map_control_0dac8b:
    .byte $E0 ; previous-row copy escape
    .byte $B7 ; row-distance/count
