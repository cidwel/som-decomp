.setcpu "65816"
.segment "CODE"
.org $1850
map_control_0e1850:
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
