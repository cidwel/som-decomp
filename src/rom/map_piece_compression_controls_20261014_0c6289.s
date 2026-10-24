.setcpu "65816"
.segment "CODE"
.org $6289
map_control_0c6289:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
