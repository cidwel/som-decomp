.setcpu "65816"
.segment "CODE"
.org $1830
map_control_0e1830:
    .byte $EB ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
