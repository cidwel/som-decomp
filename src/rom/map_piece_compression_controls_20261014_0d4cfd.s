.setcpu "65816"
.segment "CODE"
.org $4CFD
map_control_0d4cfd:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
