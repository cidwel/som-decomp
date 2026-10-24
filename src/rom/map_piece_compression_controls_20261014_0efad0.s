.setcpu "65816"
.segment "CODE"
.org $FAD0
map_control_0efad0:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E1 ; previous-row copy count
