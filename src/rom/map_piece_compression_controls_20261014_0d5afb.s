.setcpu "65816"
.segment "CODE"
.org $5AFB
map_control_0d5afb:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
