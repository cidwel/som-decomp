.setcpu "65816"
.segment "CODE"
.org $994C
map_control_0d994c:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
