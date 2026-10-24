.setcpu "65816"
.segment "CODE"
.org $5E3A
map_control_0f5e3a:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
