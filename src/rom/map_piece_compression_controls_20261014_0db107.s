.setcpu "65816"
.segment "CODE"
.org $B107
map_control_0db107:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $21 ; distance low bit/count
