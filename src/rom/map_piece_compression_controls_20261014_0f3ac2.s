.setcpu "65816"
.segment "CODE"
.org $3AC2
map_control_0f3ac2:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
