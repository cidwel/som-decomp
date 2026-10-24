.setcpu "65816"
.segment "CODE"
.org $53EB
map_control_0f53eb:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
