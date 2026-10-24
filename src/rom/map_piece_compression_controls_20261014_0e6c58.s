.setcpu "65816"
.segment "CODE"
.org $6C58
map_control_0e6c58:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
