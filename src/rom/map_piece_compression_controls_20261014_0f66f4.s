.setcpu "65816"
.segment "CODE"
.org $66F4
map_control_0f66f4:
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $31 ; distance low bit/count
