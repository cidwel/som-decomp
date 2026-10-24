.setcpu "65816"
.segment "CODE"
.org $DE84
map_control_0dde84:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
