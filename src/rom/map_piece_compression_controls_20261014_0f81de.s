.setcpu "65816"
.segment "CODE"
.org $81DE
map_control_0f81de:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
