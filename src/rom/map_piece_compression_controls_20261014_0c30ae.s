.setcpu "65816"
.segment "CODE"
.org $30AE
map_control_0c30ae:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
