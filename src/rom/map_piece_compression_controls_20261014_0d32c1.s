.setcpu "65816"
.segment "CODE"
.org $32C1
map_control_0d32c1:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
