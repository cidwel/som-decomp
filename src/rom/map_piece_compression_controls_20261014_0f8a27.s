.setcpu "65816"
.segment "CODE"
.org $8A27
map_control_0f8a27:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
