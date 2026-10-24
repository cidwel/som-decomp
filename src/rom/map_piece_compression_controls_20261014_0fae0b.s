.setcpu "65816"
.segment "CODE"
.org $AE0B
map_control_0fae0b:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
