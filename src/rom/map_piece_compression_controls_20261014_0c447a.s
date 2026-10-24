.setcpu "65816"
.segment "CODE"
.org $447A
map_control_0c447a:
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
