.setcpu "65816"
.segment "CODE"
.org $3A27
map_control_0c3a27:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
