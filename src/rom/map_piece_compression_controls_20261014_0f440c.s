.setcpu "65816"
.segment "CODE"
.org $440C
map_control_0f440c:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $42 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $3C ; distance low bit/count
