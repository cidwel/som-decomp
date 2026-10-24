.setcpu "65816"
.segment "CODE"
.org $1479
map_control_0e1479:
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
