.setcpu "65816"
.segment "CODE"
.org $660C
map_control_0f660c:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
