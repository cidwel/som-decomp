.setcpu "65816"
.segment "CODE"
.org $151E
map_control_0d151e:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
