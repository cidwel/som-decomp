.setcpu "65816"
.segment "CODE"
.org $0F0C
map_control_0e0f0c:
    .byte $EF ; backreference distance high bits
    .byte $1C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
