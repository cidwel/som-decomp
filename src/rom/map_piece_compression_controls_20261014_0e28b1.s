.setcpu "65816"
.segment "CODE"
.org $28B1
map_control_0e28b1:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
