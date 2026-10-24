.setcpu "65816"
.segment "CODE"
.org $C98B
map_control_0dc98b:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
