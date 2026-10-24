.setcpu "65816"
.segment "CODE"
.org $53B4
map_control_0d53b4:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
