.setcpu "65816"
.segment "CODE"
.org $015B
map_control_0e015b:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
