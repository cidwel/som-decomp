.setcpu "65816"
.segment "CODE"
.org $0F11
map_control_0e0f11:
    .byte $EF ; backreference distance high bits
    .byte $1C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
