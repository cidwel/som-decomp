.setcpu "65816"
.segment "CODE"
.org $1866
map_control_0e1866:
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
