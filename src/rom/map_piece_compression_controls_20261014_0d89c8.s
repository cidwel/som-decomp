.setcpu "65816"
.segment "CODE"
.org $89C8
map_control_0d89c8:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
