.setcpu "65816"
.segment "CODE"
.org $F7B5
map_control_0ff7b5:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
