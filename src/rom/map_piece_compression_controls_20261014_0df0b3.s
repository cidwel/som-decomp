.setcpu "65816"
.segment "CODE"
.org $F0B3
map_control_0df0b3:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
