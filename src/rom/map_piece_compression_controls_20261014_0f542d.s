.setcpu "65816"
.segment "CODE"
.org $542D
map_control_0f542d:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
