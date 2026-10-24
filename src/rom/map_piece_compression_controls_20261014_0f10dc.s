.setcpu "65816"
.segment "CODE"
.org $10DC
map_control_0f10dc:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
