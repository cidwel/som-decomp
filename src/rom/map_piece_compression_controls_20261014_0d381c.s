.setcpu "65816"
.segment "CODE"
.org $381C
map_control_0d381c:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
