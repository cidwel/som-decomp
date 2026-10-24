.setcpu "65816"
.segment "CODE"
.org $C4A5
map_control_0fc4a5:
    .byte $EC ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $29 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
