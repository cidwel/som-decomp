.setcpu "65816"
.segment "CODE"
.org $81F8
map_control_0d81f8:
    .byte $E0 ; previous-row copy escape
    .byte $4C ; row-distance/count
