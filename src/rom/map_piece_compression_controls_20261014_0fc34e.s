.setcpu "65816"
.segment "CODE"
.org $C34E
map_control_0fc34e:
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
