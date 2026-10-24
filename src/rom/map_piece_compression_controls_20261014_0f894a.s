.setcpu "65816"
.segment "CODE"
.org $894A
map_control_0f894a:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
