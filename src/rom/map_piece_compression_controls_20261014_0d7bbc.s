.setcpu "65816"
.segment "CODE"
.org $7BBC
map_control_0d7bbc:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
