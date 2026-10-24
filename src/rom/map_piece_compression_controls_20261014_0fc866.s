.setcpu "65816"
.segment "CODE"
.org $C866
map_control_0fc866:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
