.setcpu "65816"
.segment "CODE"
.org $1238
map_control_0e1238:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
