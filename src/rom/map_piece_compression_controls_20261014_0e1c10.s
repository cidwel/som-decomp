.setcpu "65816"
.segment "CODE"
.org $1C10
map_control_0e1c10:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
