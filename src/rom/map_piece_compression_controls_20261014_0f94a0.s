.setcpu "65816"
.segment "CODE"
.org $94A0
map_control_0f94a0:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
