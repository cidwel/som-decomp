.setcpu "65816"
.segment "CODE"
.org $86D9
map_control_0c86d9:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
