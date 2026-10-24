.setcpu "65816"
.segment "CODE"
.org $7FAE
map_control_0c7fae:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
