.setcpu "65816"
.segment "CODE"
.org $6C77
map_control_0e6c77:
    .byte $E0 ; previous-row copy escape
    .byte $62 ; row-distance/count
