.setcpu "65816"
.segment "CODE"
.org $CE55
map_control_0fce55:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
