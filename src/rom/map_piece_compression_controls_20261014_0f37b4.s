.setcpu "65816"
.segment "CODE"
.org $37B4
map_control_0f37b4:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
