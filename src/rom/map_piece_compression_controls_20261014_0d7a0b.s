.setcpu "65816"
.segment "CODE"
.org $7A0B
map_control_0d7a0b:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
