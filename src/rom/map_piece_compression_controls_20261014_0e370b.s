.setcpu "65816"
.segment "CODE"
.org $370B
map_control_0e370b:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $52 ; distance low bit/count
