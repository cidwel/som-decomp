.setcpu "65816"
.segment "CODE"
.org $9887
map_control_0f9887:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
