.setcpu "65816"
.segment "CODE"
.org $3CA0
map_control_0d3ca0:
    .byte $E3 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $23 ; distance low bit/count
