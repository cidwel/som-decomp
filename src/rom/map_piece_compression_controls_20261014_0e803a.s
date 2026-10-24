.setcpu "65816"
.segment "CODE"
.org $803A
map_control_0e803a:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
