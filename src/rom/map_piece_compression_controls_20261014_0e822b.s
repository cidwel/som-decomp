.setcpu "65816"
.segment "CODE"
.org $822B
map_control_0e822b:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
