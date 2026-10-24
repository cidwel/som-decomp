.setcpu "65816"
.segment "CODE"
.org $81F8
map_control_0f81f8:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
