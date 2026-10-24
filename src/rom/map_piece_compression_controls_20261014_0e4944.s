.setcpu "65816"
.segment "CODE"
.org $4944
map_control_0e4944:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
