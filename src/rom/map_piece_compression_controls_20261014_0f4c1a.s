.setcpu "65816"
.segment "CODE"
.org $4C1A
map_control_0f4c1a:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
