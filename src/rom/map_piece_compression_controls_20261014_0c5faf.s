.setcpu "65816"
.segment "CODE"
.org $5FAF
map_control_0c5faf:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
