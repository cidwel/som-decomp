.setcpu "65816"
.segment "CODE"
.org $5F6D
map_control_0f5f6d:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
