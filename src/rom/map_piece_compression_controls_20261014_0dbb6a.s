.setcpu "65816"
.segment "CODE"
.org $BB6A
map_control_0dbb6a:
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
