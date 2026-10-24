.setcpu "65816"
.segment "CODE"
.org $9A0B
map_control_0f9a0b:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
