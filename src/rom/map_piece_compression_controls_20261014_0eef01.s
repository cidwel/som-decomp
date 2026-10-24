.setcpu "65816"
.segment "CODE"
.org $EF01
map_control_0eef01:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
