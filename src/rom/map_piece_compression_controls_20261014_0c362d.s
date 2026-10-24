.setcpu "65816"
.segment "CODE"
.org $362D
map_control_0c362d:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
