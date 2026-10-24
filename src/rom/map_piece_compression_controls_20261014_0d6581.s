.setcpu "65816"
.segment "CODE"
.org $6581
map_control_0d6581:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
