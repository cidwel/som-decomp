.setcpu "65816"
.segment "CODE"
.org $263B
map_control_0d263b:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
