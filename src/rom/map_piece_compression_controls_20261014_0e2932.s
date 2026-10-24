.setcpu "65816"
.segment "CODE"
.org $2932
map_control_0e2932:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
