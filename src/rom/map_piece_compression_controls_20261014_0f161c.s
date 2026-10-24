.setcpu "65816"
.segment "CODE"
.org $161C
map_control_0f161c:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
