.setcpu "65816"
.segment "CODE"
.org $716E
map_control_0f716e:
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
