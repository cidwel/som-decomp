.setcpu "65816"
.segment "CODE"
.org $C2E4
map_control_0dc2e4:
    .byte $ED ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
