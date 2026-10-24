.setcpu "65816"
.segment "CODE"
.org $5944
map_control_0d5944:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
