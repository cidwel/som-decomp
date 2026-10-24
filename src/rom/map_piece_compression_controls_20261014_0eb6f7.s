.setcpu "65816"
.segment "CODE"
.org $B6F7
map_control_0eb6f7:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
