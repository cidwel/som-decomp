.setcpu "65816"
.segment "CODE"
.org $5FFD
map_control_0f5ffd:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
    .byte $EB ; backreference distance high bits
    .byte $07 ; distance low bit/count
