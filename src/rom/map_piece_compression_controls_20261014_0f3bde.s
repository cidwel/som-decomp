.setcpu "65816"
.segment "CODE"
.org $3BDE
map_control_0f3bde:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
