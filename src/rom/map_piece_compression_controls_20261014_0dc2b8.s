.setcpu "65816"
.segment "CODE"
.org $C2B8
map_control_0dc2b8:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
