.setcpu "65816"
.segment "CODE"
.org $83E4
map_control_0e83e4:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
