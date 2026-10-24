.setcpu "65816"
.segment "CODE"
.org $F75D
map_control_0cf75d:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
