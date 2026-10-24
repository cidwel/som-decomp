.setcpu "65816"
.segment "CODE"
.org $C8C1
map_control_0ec8c1:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
