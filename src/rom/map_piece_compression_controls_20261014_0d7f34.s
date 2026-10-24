.setcpu "65816"
.segment "CODE"
.org $7F34
map_control_0d7f34:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
