.setcpu "65816"
.segment "CODE"
.org $5BCB
map_control_0f5bcb:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
