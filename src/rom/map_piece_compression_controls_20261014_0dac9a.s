.setcpu "65816"
.segment "CODE"
.org $AC9A
map_control_0dac9a:
    .byte $E0 ; previous-row copy escape
    .byte $B7 ; row-distance/count
