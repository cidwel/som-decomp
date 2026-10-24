.setcpu "65816"
.segment "CODE"
.org $7FAE
map_control_0f7fae:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
