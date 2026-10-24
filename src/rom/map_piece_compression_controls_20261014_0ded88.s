.setcpu "65816"
.segment "CODE"
.org $ED88
map_control_0ded88:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
