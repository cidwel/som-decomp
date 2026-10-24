.setcpu "65816"
.segment "CODE"
.org $E001
map_control_0de001:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
