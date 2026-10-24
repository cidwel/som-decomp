.setcpu "65816"
.segment "CODE"
.org $0D8A
map_control_0d0d8a:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
