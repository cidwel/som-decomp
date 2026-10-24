.setcpu "65816"
.segment "CODE"
.org $8D1A
map_control_0c8d1a:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
