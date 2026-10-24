.setcpu "65816"
.segment "CODE"
.org $75A3
map_control_0c75a3:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3E ; row-distance/count
