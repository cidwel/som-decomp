.setcpu "65816"
.segment "CODE"
.org $E283
map_control_0de283:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
