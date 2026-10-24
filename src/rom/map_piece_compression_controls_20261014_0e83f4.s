.setcpu "65816"
.segment "CODE"
.org $83F4
map_control_0e83f4:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
