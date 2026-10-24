.setcpu "65816"
.segment "CODE"
.org $81C2
map_control_0d81c2:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
