.setcpu "65816"
.segment "CODE"
.org $06A0
map_control_0f06a0:
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
