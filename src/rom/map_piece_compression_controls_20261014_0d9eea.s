.setcpu "65816"
.segment "CODE"
.org $9EEA
map_control_0d9eea:
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
