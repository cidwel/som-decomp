.setcpu "65816"
.segment "CODE"
.org $BD98
map_control_0ebd98:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
