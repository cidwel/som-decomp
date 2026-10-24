.setcpu "65816"
.segment "CODE"
.org $60EB
map_control_0d60eb:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
