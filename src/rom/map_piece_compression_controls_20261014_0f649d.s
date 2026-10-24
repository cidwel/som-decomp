.setcpu "65816"
.segment "CODE"
.org $649D
map_control_0f649d:
    .byte $EB ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
