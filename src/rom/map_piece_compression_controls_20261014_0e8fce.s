.setcpu "65816"
.segment "CODE"
.org $8FCE
map_control_0e8fce:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
