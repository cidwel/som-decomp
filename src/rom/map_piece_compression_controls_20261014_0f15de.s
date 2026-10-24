.setcpu "65816"
.segment "CODE"
.org $15DE
map_control_0f15de:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
