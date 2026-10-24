.setcpu "65816"
.segment "CODE"
.org $EA1C
map_control_0eea1c:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
