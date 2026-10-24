.setcpu "65816"
.segment "CODE"
.org $1B76
map_control_0e1b76:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
