.setcpu "65816"
.segment "CODE"
.org $8C28
map_control_0d8c28:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
