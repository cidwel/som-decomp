.setcpu "65816"
.segment "CODE"
.org $C256
map_control_0fc256:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $25 ; distance low bit/count
