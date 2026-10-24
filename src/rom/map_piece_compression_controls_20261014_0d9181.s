.setcpu "65816"
.segment "CODE"
.org $9181
map_control_0d9181:
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
