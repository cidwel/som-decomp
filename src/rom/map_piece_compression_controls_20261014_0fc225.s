.setcpu "65816"
.segment "CODE"
.org $C225
map_control_0fc225:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
