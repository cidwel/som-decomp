.setcpu "65816"
.segment "CODE"
.org $C73E
map_control_0fc73e:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
