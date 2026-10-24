.setcpu "65816"
.segment "CODE"
.org $2BD2
map_control_0e2bd2:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $62 ; row-distance/count
