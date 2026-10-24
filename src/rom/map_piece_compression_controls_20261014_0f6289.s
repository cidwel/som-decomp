.setcpu "65816"
.segment "CODE"
.org $6289
map_control_0f6289:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
