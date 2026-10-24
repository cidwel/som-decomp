.setcpu "65816"
.segment "CODE"
.org $53A4
map_control_0e53a4:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
