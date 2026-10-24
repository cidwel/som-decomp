.setcpu "65816"
.segment "CODE"
.org $1B8C
map_control_0e1b8c:
    .byte $E4 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
